uniform sampler2D u_texture;
uniform highp vec4 u_lightPosition;
uniform highp float u_lightPower;
uniform highp vec3 u_coef[16];
varying highp vec4 v_position;
varying highp vec2 v_texcoord;
varying highp vec3 v_normal;

const float PI = 3.1415926535897932384626433832795;

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
	vec4 diffMatColor = texture2D(u_texture, v_texcoord);

	float x = v_normal.x;
	float y = v_normal.y;
	float z = v_normal.z;
	float x2 = x * x;
	float y2 = y * y;
	float z2 = z * z;

	float basis[16];
	basis[0] = 1.0f / 2.0f * sqrt(1.0f / PI);
	basis[1] = sqrt(3.0f / (4.0f * PI)) * z;
	basis[2] = sqrt(3.0f / (4.0f * PI)) * y;
	basis[3] = sqrt(3.0f / (4.0f * PI)) * x;
	basis[4] = 1.0f / 2.0f * sqrt(15.0f / PI) * x * z;
	basis[5] = 1.0f / 2.0f * sqrt(15.0f / PI) * z * y;
	basis[6] = 1.0f / 4.0f * sqrt(5.0f / PI) * (-x * x - z * z + 2.0f * y * y);
	basis[7] = 1.0f / 2.0f * sqrt(15.0f / PI) * y * x;
	basis[8] = 1.0f / 4.0f * sqrt(15.0f / PI) * (x * x - z * z);
	basis[9] = 1.0f / 4.0f * sqrt(35.0f / (2.0f * PI)) * (3.0f * x2 - z2) * z;
	basis[10] = 1.0f / 2.0f * sqrt(105.0f / PI) * x * z * y;
	basis[11] = 1.0f / 4.0f * sqrt(21.0f / (2.0f * PI)) * z * (4.0f * y2 - x2 - z2);
	basis[12] = 1.0f / 4.0f * sqrt(7.0f / PI) * y * (2.0f * y2 - 3.0f * x2 - 3.0f * z2);
	basis[13] = 1.0f / 4.0f * sqrt(21.0f / (2.0f * PI)) * x * (4.0f * y2 - x2 - z2);
	basis[14] = 1.0f / 4.0f * sqrt(105.0f / PI) * (x2 - z2) * y;
	basis[15] = 1.0f / 4.0f * sqrt(35.0f / (2.0f * PI)) * (x2 - 3.0f * z2) * x;

	vec3 shColor = vec3(0.0, 0.0, 0.0);
	for (int i = 0; i < 16; i++)
		shColor += u_coef[i] * basis[i];

	diffMatColor *= vec4(shColor, 1.0);

	gl_FragColor = diffMatColor;
}