#version 330 core

in highp vec4 a_position;
in highp vec2 a_texcoord;
in highp vec3 a_normal;

uniform highp mat4 u_modelMatrix;
uniform highp mat4 u_projectionMatrix;
uniform highp mat4 u_viewMatrix;
uniform highp vec4 u_rotationQuat;

out highp vec2 v_texcoord;
out highp vec3 v_normal;
out highp vec4 v_position;
out highp mat4 v_viewMatrix;

void main(void) {
	// passing parameters	
	v_texcoord = a_texcoord;
	v_normal = mat3(transpose(inverse(u_modelMatrix))) * a_normal;
	v_position = u_modelMatrix * a_position;
	v_viewMatrix = u_viewMatrix;

	// vertices
	gl_Position = u_projectionMatrix * u_viewMatrix * u_modelMatrix * a_position;
}