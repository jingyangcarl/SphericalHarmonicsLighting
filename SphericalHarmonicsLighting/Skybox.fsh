#version 330 core

// uniform sampler2D u_texture;
uniform samplerCube u_texture;

// in highp vec2 v_texcoord;
in highp vec3 v_texcoord;

out highp vec4 FragColor;

void main(void) {
	FragColor = vec4(texture(u_texture, v_texcoord).rgb, 1.0);
}