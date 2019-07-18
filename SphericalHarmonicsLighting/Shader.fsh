uniform sampler2D u_texture;
uniform sampler2D u_skyboxTexture;

varying highp vec4 v_position;
varying highp vec3 v_normal;

void main(void) {

	vec4 eyePosition = vec4(1.0, 0.0, 0.0, 1.0);
	vec3 eyeVec = normalize(v_position - eyePosition);
	vec3 R = reflect(eyeVec, normalize(v_normal));

	gl_FragColor = vec4(texture2D(u_skyboxTexture, R).rgb, 1.0) * 0.5;
	// gl_FragColor = texture2D(u_skyboxTexture, v_texcoord);
}
