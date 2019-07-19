#version 330 core

in highp vec4 a_position;
in highp vec2 a_texcoord;
in highp vec3 a_normal;

uniform highp mat4 u_modelMatrix;
uniform highp mat4 u_projectionMatrix;
uniform highp mat4 u_viewMatrix;

out highp vec2 v_texcoord;
out highp vec3 v_normal;
out highp vec3 v_position;

void main(void) {
	// passing parameters	
	v_texcoord = a_texcoord;
	v_normal = mat3(transpose(inverse(u_modelMatrix))) * a_normal;
	v_position = vec3(u_modelMatrix * a_position);

	// vertices
	mat4 mv_matrix = u_viewMatrix * u_modelMatrix;
	gl_Position = u_projectionMatrix * mv_matrix * a_position;
}