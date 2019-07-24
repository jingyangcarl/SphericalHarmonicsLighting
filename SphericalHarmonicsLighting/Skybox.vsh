#version 330 core

uniform highp mat4 u_modelMatrix;
uniform highp mat4 u_projectionMatrix;
uniform highp mat4 u_viewMatrix;

in highp vec4 a_position;
in highp vec2 a_texcoord;
in highp vec3 a_normal;

out highp vec4 v_position;

void main(void) {
	// passing parameters
	v_position = a_position;

	// vertices
	gl_Position = u_projectionMatrix * u_viewMatrix * u_modelMatrix * a_position;
}