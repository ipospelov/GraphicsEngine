#version 110

varying vec4 TexCoord0;
attribute vec3 position;
attribute vec3 v_coord;
uniform mat4 matrixWorldViewProjT;

void main(){
    gl_Position = vec4(position, 1.0) * matrixWorldViewProjT;
    TexCoord0 = vec4(position, 1.0);
}