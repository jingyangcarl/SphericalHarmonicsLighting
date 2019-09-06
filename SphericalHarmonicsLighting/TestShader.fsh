#version 330 core

uniform sampler2D u_texture;
uniform highp vec4 u_lightPosition;
uniform highp float u_lightPower;
uniform highp float u_ambientFactor;
uniform highp float u_contrast;
uniform highp float u_brightness;
uniform highp vec3 u_coef[16];

in highp vec4 v_position;
in highp vec2 v_texcoord;
in highp vec3 v_normal;
in highp mat4 v_viewMatrix;

out highp vec4 FragColor;

const float M_PI = 3.14159265358979323846;

void main(void) {

	// ADS model
	//vec4 resultColor = vec4(0.0, 0.0, 0.0, 0.0);
	//vec4 eyePosition = vec4(1.0, 0.0, 0.0, 1.0);
	// vec4 diffMatColor = texture2D(u_texture, v_texcoord);
	//vec4 diffMatColor = vec4(1.0, 1.0, 1.0, 1.0);
	//vec3 eyeVec = normalize(v_position.xyz - eyePosition.xyz);
	//vec3 lightVec = normalize(v_position.xyz - u_lightPosition.xyz);
	//vec3 reflectLight = normalize(reflect(lightVec, v_normal));

	//float len = length(v_position.xyz - eyePosition.xyz);
	//float specularFactor = 1.0;
	//float ambientFactor = 0.3;

	//vec4 diffColor = diffMatColor * u_lightPower * max(0.0, dot(v_normal, -lightVec));
	//resultColor += diffColor;

	//vec4 ambientColor = ambientFactor * diffMatColor;
	//resultColor += ambientColor;

	//vec4 specularColor = vec4(1.0, 1.0, 1.0, 1.0) * u_lightPower * pow(max(0.0, dot(reflectLight, -eyeVec)), specularFactor);
	//resultColor += specularColor;

	// gl_FragColor = resultColor;


	// SH
	vec4 diffMatColor = texture2D(u_texture, v_texcoord) * u_ambientFactor;
	
	mat4 normal_trans = inverse(v_viewMatrix);
	vec3 normal = vec3(normalize(normal_trans * vec4(v_normal, 0.0)));

	float x = normal.x;
	float y = normal.y;
	float z = normal.z;
	float x2 = x * x;
	float y2 = y * y;
	float z2 = z * z;

	float basis[16];
	basis[0] = 1.0f / 2.0f * sqrt(1.0f / M_PI); // check

	basis[1] = sqrt(3.0f / (4.0f * M_PI)) * y; // check
	basis[2] = sqrt(3.0f / (4.0f * M_PI)) * z; // check
	basis[3] = sqrt(3.0f / (4.0f * M_PI)) * x; // check

	basis[4] = 1.0f / 2.0f * sqrt(15.0f / M_PI) * x * y; // check
	basis[5] = 1.0f / 2.0f * sqrt(15.0f / M_PI) * z * y; // check
	basis[6] = 1.0f / 4.0f * sqrt(5.0f / M_PI) * (-x2 - y2 + 2.0f*z2); // check
	basis[7] = 1.0f / 2.0f * sqrt(15.0f / M_PI) * x * z; // check
	basis[8] = 1.0f / 4.0f * sqrt(15.0f / M_PI) * (x2 - y2); // check

	basis[9] = 1.0f / 4.0f * sqrt(35.0f / (2.0f * M_PI)) * (3.0f*x2 - y2) * y; // check
	basis[10] = 1.0f / 2.0f * sqrt(105.0f / M_PI) * x * z * y; // check
	basis[11] = 1.0f / 4.0f * sqrt(21.0f / (2.0f * M_PI)) * y * (5.0f*z2 - x2 - y2); // check
	basis[12] = 1.0f / 4.0f * sqrt(7.0f / M_PI) * z * (1.5f*z2 - 3.0f*x2 - 3.0f*y2); // check
	basis[13] = 1.0f / 4.0f * sqrt(21.0f / (2.0f * M_PI)) * x * (5.0f*z2 - x2 - y2); // check
	basis[14] = 1.0f / 4.0f * sqrt(105.0f / M_PI) * (x2 - y2) * z; // check
	basis[15] = 1.0f / 4.0f * sqrt(35.0f / (2.0f * M_PI)) * (x2 - 3.0f*y2) * x; // check

	vec3 shColor = vec3(0.0, 0.0, 0.0);
	for (int i = 0; i < 16; i++)
		shColor += u_coef[i] * basis[i];

	// adjust contrast;
	shColor = (shColor - 0.5f) * u_contrast + 0.5f;
	// adjust brightnes;
	shColor += u_brightness;

	// diffMatColor += vec4(shColor, 1.0);

	FragColor = diffMatColor;
	// FragColor = vec4(shColor, 1.0);
}