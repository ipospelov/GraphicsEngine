#version 110

varying vec4 TexCoord0;
uniform mat4 matrixWorldViewProjT;

varying vec3 localPosition;
varying vec3 localNormal;

// Vertex structure
attribute vec3 position;
attribute vec4 color;
attribute vec3 normal;



varying vec2 uv1;

void main(){
    gl_Position = vec4(position, 1.0) * matrixWorldViewProjT;
    TexCoord0 = vec4(position, 1.0);
    gl_FrontColor	= color;
    localPosition	= position;
    localNormal		= normal;
    uv1 = TexCoord0.xy;
}