#version 110

uniform sampler2D texture1;
varying vec4 TexCoord0;

void main(){

    vec2 longitudeLatitude = vec2((atan(TexCoord0.z, TexCoord0.x) / 3.1415926  + 1.0) * 0.6 ,
                                      -(asin(TexCoord0.y) / 3.1415926 + 0.45) * 1.6);
    gl_FragColor = texture2D(texture1, longitudeLatitude);

}