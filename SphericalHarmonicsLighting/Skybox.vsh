#version 330 core

uniform highp mat4 u_modelMatrix;
uniform highp mat4 u_projectionMatrix;
uniform highp mat4 u_viewMatrix;

in highp vec4 a_position;
in highp vec2 a_texcoord;
in highp vec3 a_normal;

out highp vec2 v_texcoord;

void main(void) {
	// passing parameters
	v_texcoord = a_texcoord;

	// vertices
	mat4 mv_matrix = u_viewMatrix * u_modelMatrix;
	gl_Position = u_projectionMatrix * mv_matrix * a_position;
}