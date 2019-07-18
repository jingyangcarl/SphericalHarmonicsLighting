#version 330 core

in highp vec4 a_position;
in highp vec2 a_texcoord;
in highp vec3 a_normal;

uniform highp mat4 u_modelMatrix;
uniform highp mat4 u_projectionMatrix;
uniform highp mat4 u_viewMatrix;

// pass to fragment shader
out highp vec4 v_position;
out highp vec2 v_texcoord;
out highp vec3 v_normal;
out highp mat4 v_viewMatrix;

void main(void) {

	mat4 mv_matrix = u_viewMatrix * u_modelMatrix;
	gl_Position = u_projectionMatrix * mv_matrix * a_position;

	v_texcoord = a_texcoord;
	v_normal = normalize(vec3(mv_matrix * vec4(a_normal, 0.0)));
	v_position = mv_matrix * a_position;
	v_viewMatrix = u_viewMatrix;
}