#version 330 core

uniform sampler2D u_texture;

in highp vec2 v_texcoord;

out highp vec4 FragColor;

void main(void) {
	FragColor = texture2D(u_texture, v_texcoord);
}