#version 330 core

attribute highp vec4 a_position;
attribute highp vec2 a_texcoord;
attribute highp vec3 a_normal;

uniform highp mat4 u_modelMatrix;
uniform highp mat4 u_projectionMatrix;
uniform highp mat4 u_viewMatrix;

varying highp vec2 v_texcoord;
varying highp vec3 v_normal;
varying highp vec3 v_position;

void main(void) {
	// passing parameters	
	v_texcoord = a_texcoord;
	v_normal = mat3(transpose(inverse(u_modelMatrix))) * a_normal;
	v_position = vec3(u_modelMatrix * vec4(a_position, 1.0));

	// vertices
	mat4 mv_matrix = u_viewMatrix * u_modelMatrix;
	gl_Position = u_projectionMatrix * mv_matrix * a_position;
}