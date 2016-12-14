#version 110

uniform sampler2D texture1;
uniform sampler2D texture_map;
varying vec4 TexCoord0;

struct Light
{
	vec4	type;		// тип источника
	vec4	position;	// позиция источника (есть у Point и Spot)
	vec4	direction;	// направление света
	vec4	color;		// (цвет.r, цвет.g, цвет.b, интенсивность)
};

uniform vec4 lightsCount;
uniform Light lights[3];
uniform vec4 materialColor;
uniform mat4 matWorldNormal;

varying vec3 localPosition;
varying vec3 localNormal;
vec3 local_map;
vec3 cross_map;
vec3 binormal_map;
vec3 global_map;
varying vec2 uv1;


vec3 calcDiffuse(vec4 lightCol, vec3 lightDir, vec3 vertexNormal)
{
	float diffuse = clamp( dot(-lightDir, vertexNormal), 0.0, 1.0 );

	// Цвет = diffuse * (цвет источника) * (интенсивность источника)
	vec3 color = diffuse * lightCol.rgb * lightCol.a;

	return color;
}

void main(){

     //vec2 longitudeLatitude = vec2((atan(TexCoord0.z, TexCoord0.x) / 3.1415926  + 1.0) * 0.6 ,
           //                                -(asin(TexCoord0.y) / 3.1415926 + 0.45) * 1.6);

    vec2 longitudeLatitude = uv1;
    vec3 vertexNormal = (vec4(localNormal, 0.0) * matWorldNormal).xyz;
    	vertexNormal = normalize(vertexNormal);

    local_map = normalize(texture2D(texture_map, longitudeLatitude).xyz);

    local_map.x = 2.0 * local_map.x - 1.0 ;
    local_map.y = 2.0 * local_map.y - 1.0 ;
    local_map.z = 2.0 * local_map.z - 1.0 ;
    cross_map = normalize(cross(vertexNormal, vec3(1,1,1))); // касательная к нормали
    binormal_map = normalize(cross(vertexNormal, cross_map)); //бинормаль для карты
    global_map = local_map.x * cross_map + local_map.y * binormal_map + local_map.z * vertexNormal;

     vec3 colDiffuse = vec3(0,0,0);
     vec3 lightDir = vec3(0,0,0);
     for (int i = 0; i < 3; ++i){
         if (float(i) >= lightsCount.x) break;

         float type = lights[i].type.x;
         vec4 lightCol = lights[i].color;
         float epsilon = 0.001;

         if (abs(type - 1.0) < epsilon)
            lightDir = -normalize(lights[i].direction.xyz);

         colDiffuse = materialColor.rgb * dot(global_map , lightDir);   // calcDiffuse(lightCol, lightDir, vertexNormal);//(global_map* calcDiffuse(lightCol, lightDir, localNormal)); //calcDiffuse(lightCol, lightDir, vertexNormal);
    }

    gl_FragColor = texture2D(texture1, longitudeLatitude);
    gl_FragColor += vec4(colDiffuse, 1.0);
    gl_FragColor.a = 1.0;

}