#version 330 core

uniform sampler2D u_texture;
// uniform sampler2D u_skyboxTexture;
uniform samplerCube u_skyboxTexture;

in highp vec4 v_position;
in highp vec3 v_normal;
in highp vec2 v_texcoord;

out highp vec4 FragColor;

void main(void) {

	vec4 eyePosition = vec4(1.0, 0.0, 0.0, 1.0);
	vec3 eyeVec = normalize(v_position.xyz - eyePosition.xyz);
	vec3 R = reflect(eyeVec, normalize(v_normal));

	FragColor = vec4(texture(u_skyboxTexture, R).rgb, 1.0) * 0.5;
	// FragColor = texture2D(u_texture, v_texcoord);
}
