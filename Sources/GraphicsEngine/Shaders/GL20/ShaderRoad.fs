#version 110

varying vec2 uv1;
varying vec2 uv2;
varying vec2 uv3;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform sampler2D texture3;

void main()
{
        vec2 uv1Scale = vec2(1, 100);
        vec2 uv2Scale = vec2(1, 30);
        vec2 uv3Scale = vec2(1, 20);

    vec4 texval3 = texture2D(texture3, vec2(uv1) *uv3Scale);
    vec4 texval2 = texture2D(texture2, vec2(uv1) *uv2Scale);
    vec4 texval1 = texture2D(texture1, vec2(uv1) *uv1Scale);

    //gl_FragColor = 0.33 * (texval1 + texval2 + texval3);
    gl_FragColor = texval1 * texval2 * texval3 * 2.0; //(0.5 * texval1 + 0.2 * texval2 + 0.3 * texval3);
    //gl_FragColor = (texval2);
}
