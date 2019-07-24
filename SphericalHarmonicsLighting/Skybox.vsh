#version 330 core

uniform highp mat4 u_modelMatrix;
uniform highp mat4 u_projectionMatrix;
uniform highp mat4 u_viewMatrix;

in highp vec4 i_position;
// in highp vec2 i_texcoord;
// in highp vec3 i_normal;

out highp vec4 o_position;

void main(void) {
	// passing parameters
	o_position = i_position;

	// vertices
	gl_Position = u_projectionMatrix * u_viewMatrix * u_modelMatrix * i_position;
}