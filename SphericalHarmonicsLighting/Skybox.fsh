#version 330 core

uniform sampler2D u_texture;

in highp vec2 v_texcoord;

void main(void) {
	gl_FragColor = texture2D(u_texture, v_texcoord);
}