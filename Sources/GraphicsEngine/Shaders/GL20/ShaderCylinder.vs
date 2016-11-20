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
uniform mat4 matrixWorldViewProjT;
uniform mat4 matrixWorldViewProjT2;

void main()
{	
	float h = (position.y + 1.0) * 0.5;
	mat4 M1 = matrixWorldViewProjT;
	mat4 M2 = matrixWorldViewProjT2;  
	mat4 M = M1 * (1.0 - h) + M2 * h;
	
	gl_Position = vec4(position, 1.0) * M;
	gl_FrontColor = color;
}
