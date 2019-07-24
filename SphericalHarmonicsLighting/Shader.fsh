#version 330 core

uniform sampler2D u_texture;
uniform samplerCube u_skyboxTexture;

uniform highp float u_materialType;
const float DIFFUSE = 0.0f;
const float DIFFUSE_SH = 1.0f;
const float MIRROR = 2.0f;
const float GLASS = 3.0f;

uniform highp vec3 u_coef[16];
uniform highp float u_ambientFactor;
uniform highp float u_contrast;
uniform highp float u_brightness;
const float M_PI = 3.14159265358979323846;

uniform highp float u_refractRatio;

in highp vec4 v_position;
in highp vec3 v_normal;
in highp vec2 v_texcoord;
in highp mat4 v_viewMatrix;
in highp vec4 v_rotation;

out highp vec4 FragColor;

void main(void) {

	if (u_materialType == DIFFUSE) {
		
		vec4 eyePosition = v_viewMatrix[3];
		eyePosition = mat4(mat3(v_viewMatrix)) * eyePosition;
		vec4 lightPosition = vec4(0.0, 0.0, 1.0, 1.0);
		vec3 lightVec = normalize(v_position.xyz - lightPosition.xyz);
		float lightPower = 3.0f;

		// 
		vec4 diffMapColor = texture2D(u_texture, v_texcoord);

		// diffuse Color
		vec4 diffColor = lightPower * max(0.0, dot(v_normal, -lightVec)) * diffMapColor;

		// ambient Color
		vec4 ambientColor = u_ambientFactor * diffMapColor;

		// ads Color
		vec4 adsColor = diffColor + ambientColor;

		// contrast;
		adsColor = (adsColor - 0.5f) * u_contrast + 0.5f;

		// brightness;
		adsColor += u_brightness;

		FragColor = adsColor;
	}
	else if (u_materialType == DIFFUSE_SH) {
		// diffuse spherical harmonics lighting
		vec4 diffuseColor = texture2D(u_texture, v_texcoord) * u_ambientFactor;
		
		// mat4 normal_trans = inverse(v_viewMatrix);
		// vec3 normal = vec3(normalize(normal_trans * vec4(v_normal, 0.0)));
		vec3 normal = vec3(normalize(v_normal));

		// spherical harmonics lighting
		float x = normal.x;
		float y = normal.y;
		float z = normal.z;
		float x2 = x * x;
		float y2 = y * y;
		float z2 = z * z;

		// basis 
		float basis[16];
		// level 0
		basis[0] = 1.0f / 2.0f * sqrt(1.0f / M_PI); // check
		// level 1
		basis[1] = sqrt(3.0f / (4.0f * M_PI)) * y; // check
		basis[2] = sqrt(3.0f / (4.0f * M_PI)) * z; // check
		basis[3] = sqrt(3.0f / (4.0f * M_PI)) * x; // check
		// level 2
		basis[4] = 1.0f / 2.0f * sqrt(15.0f / M_PI) * x * y; // check
		basis[5] = 1.0f / 2.0f * sqrt(15.0f / M_PI) * z * y; // check
		basis[6] = 1.0f / 4.0f * sqrt(5.0f / M_PI) * (-x2 - y2 + 2.0f*z2); // check
		basis[7] = 1.0f / 2.0f * sqrt(15.0f / M_PI) * x * z; // check
		basis[8] = 1.0f / 4.0f * sqrt(15.0f / M_PI) * (x2 - y2); // check
		// level 3
		basis[9] = 1.0f / 4.0f * sqrt(35.0f / (2.0f * M_PI)) * (3.0f*x2 - y2) * y; // check
		basis[10] = 1.0f / 2.0f * sqrt(105.0f / M_PI) * x * z * y; // check
		basis[11] = 1.0f / 4.0f * sqrt(21.0f / (2.0f * M_PI)) * y * (5.0f*z2 - x2 - y2); // check
		basis[12] = 1.0f / 4.0f * sqrt(7.0f / M_PI) * z * (1.5f*z2 - 3.0f*x2 - 3.0f*y2); // check
		basis[13] = 1.0f / 4.0f * sqrt(21.0f / (2.0f * M_PI)) * x * (5.0f*z2 - x2 - y2); // check
		basis[14] = 1.0f / 4.0f * sqrt(105.0f / M_PI) * (x2 - y2) * z; // check
		basis[15] = 1.0f / 4.0f * sqrt(35.0f / (2.0f * M_PI)) * (x2 - 3.0f*y2) * x; // check

		// spherical harmonic lighting
		vec3 shColor = vec3(0.0, 0.0, 0.0);
		for (int i = 0; i < 16; i++) shColor += u_coef[i] * basis[i];

		// contrast
		shColor = (shColor - 0.5f) * u_contrast + 0.5f;
		// brightnes
		shColor += u_brightness;

		// add spherical harmonic lighting
		diffuseColor += vec4(shColor, 1.0);

		FragColor = diffuseColor;
	}
	else if (u_materialType == MIRROR) {
		// reflection: mirror

		vec4 eyePosition = mat4(mat3(v_viewMatrix)) * v_viewMatrix[3];
		//vec3 eyePosition = vec3(v_viewMatrix[3].xyz);
		// eyePosition = eyePosition + 2.0 * cross(cross(eyePosition, v_rotation.xyz) + v_rotation.w * eyePosition, v_rotation.xyz);
		vec3 eyeVec = normalize(v_position.xyz - eyePosition.xyz);
		eyeVec.z = -eyeVec.z;

		vec3 R = reflect(eyeVec, normalize(v_normal));
		FragColor = vec4(texture(u_skyboxTexture, R).rgb, 1.0) * 0.5;
	}
	else if (u_materialType == GLASS) {
		// refraction: glass

		vec4 eyePosition = mat4(mat3(v_viewMatrix)) * v_viewMatrix[3];
		vec3 eyeVec = normalize(v_position.xyz - eyePosition.xyz);
		eyeVec.z = -eyeVec.z;

		vec3 R = refract(eyeVec, normalize(v_normal), u_refractRatio);
		FragColor = vec4(texture(u_skyboxTexture, R).rgb, 1.0);
	}
}
