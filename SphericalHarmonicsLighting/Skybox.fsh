#version 330 core

uniform samplerCube u_texture;

in highp vec4 v_position;

out highp vec4 FragColor;

void main(void) {
	FragColor = vec4(texture(u_texture, v_position.xyz).rgb, 1.0);
}