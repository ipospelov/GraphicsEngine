#version 110

// Vertex structure
// Set order of vertex structure (position, color)
// Search in C++ code funciton GL20Mesh::Render()
// glVertexAttribPointer(0, ...) // this is "position"
// glVertexAttribPointer(1, ...) // this is "color"
attribute vec3 position;
attribute vec4 color;

// Shader parameters
// Search in C++ code functions like "glUniform4"
// i.e. functions: glUniform4fv(), glUniformMatrix4fv().
// These functions pass to shader parameters listed below
uniform vec4 vect;
uniform mat4 matrixWorldViewProjT;

void main()
{	
	vec3 v1 = position;
	vec3 v2 = normalize(position);
	float t = vect.x;
	vec3 v = v1 * (1.0 - t) + v2 * t;  
	
	gl_Position = vec4(v, 1.0) * matrixWorldViewProjT;
	gl_FrontColor = color;
}
