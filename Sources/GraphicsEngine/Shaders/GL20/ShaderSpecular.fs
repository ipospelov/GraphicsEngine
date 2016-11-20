#version 110

struct Light
{
	vec4	type;		// тип источника
	vec4	position;	// позиция источника (есть у Point и Spot)
	vec4	direction;	// направление света
	vec4	color;		// (цвет.r, цвет.g, цвет.b, интенсивность)
};

// Shader parameters
uniform mat4 matWorldNormal;
uniform mat4 matWorldT;
uniform mat4 matViewInversed;
uniform vec4 materialColor;
uniform vec4 lightsCount;
uniform Light lights[3];

varying vec3 localPosition;
varying vec3 localNormal;


vec3 calcSpecular(vec3 fragmentToCamera, vec3 lightDir, vec3 normal, vec4 lightCol)
{
    float materialSpecularFactor = 9.0;
    vec3 lightReflect = normalize(reflect(lightDir, normal));

	float SpecularFactor = pow(max(0.0, dot(fragmentToCamera, lightReflect)), materialSpecularFactor) *0.6;
	vec3 color = SpecularFactor * lightCol.rgb * lightCol.a ;

	return color;
}


void main()
{
	vec3 col = vec3(0,0,0);




	// Переводим нормаль из локальной в глобальную систему координат
	vec3 vertexNormal = (vec4(localNormal, 0.0) * matWorldNormal).xyz;

    vec3 cameraPos = vec3(matViewInversed[3]);

	// Переводим позицию из локальной в глобальную систему координат
	vec3 vertexPos = (vec4(localPosition, 1.0) * matWorldT).xyz;

	for (int i = 0; i < 3; ++i)
	{
		// Выходим, как только закончились источники освещения
                if (float(i) >= lightsCount.x) break;

		float type = lights[i].type.x;
		float epsilon = 0.001;

		vec4 lightCol = lights[i].color;
		vec3 lightDir = vec3(0,0,0);

		// Directional light
                if (abs(type - 1.0) < epsilon)
		//{
			lightDir = lights[i].direction.xyz;
			vec3 normal  = normalize(vertexNormal);
			vec3 fragmentToCamera = normalize(cameraPos - vertexPos);
		//}


		col += calcSpecular(fragmentToCamera, lightDir, normal, lightCol);
	}
	col *= materialColor.rgb;

	gl_FragColor += vec4(col, 1.0);
        gl_FragColor.a = 1.0;
}
