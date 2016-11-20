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
uniform vec4 materialColor;
uniform mat4 matViewInversed;
uniform vec4 lightsCount;
uniform Light lights[3];

varying vec3 localPosition;
varying vec3 localNormal;


vec3 calcDiffuse(vec4 lightCol, vec3 lightDir, vec3 vertexNormal)
{
	float diffuse = clamp( dot(-lightDir, vertexNormal), 0.0, 1.0 );

	// Цвет = diffuse * (цвет источника) * (интенсивность источника)
	vec3 color = diffuse * lightCol.rgb * lightCol.a;

	return color;
}

vec3 calcSpecular(vec3 fragmentToCamera, vec3 lightDir, vec3 normal, vec3 lightCol){

    float materialSpecularFactor = 50.0;
    vec3 lightReflect = normalize(reflect(lightDir, normal));

	float SpecularFactor = pow(max(0.0, dot(fragmentToCamera, lightReflect)), materialSpecularFactor) * 1.0;
	vec3 color = SpecularFactor * lightCol.rgb;// * lightCol.a ;

	return color;
}

float calcSpotLight(vec3 normal, vec3 fragmentToCamera, Light light, vec3 vertexPos) {

    float cutoff = 0.5;
    vec3 spotLightDirection = normalize(vertexPos - light.position.xyz);
    float spotAngleCos = dot(spotLightDirection, light.direction.xyz);
    float attenuation = (1.0 - 1.0*(1.0 - spotAngleCos) / (1.0 - cutoff));
    float spotFactor = float(spotAngleCos > cutoff) * attenuation;
    return spotFactor + 0.5;

}

float calcLightAttenuation(vec3 vertexPos, vec4 lightPos) {

  vec3 lightDirection = normalize(vertexPos - lightPos.xyz);
  float distance = length(vertexPos - lightPos.xyz);
  float pointFactor = 1.0 / (1.0 + pow(distance, 2));
  return pointFactor;

}

void main()
{
    vec3 col = vec3(0,0,0);
	vec3 colDiffuse = vec3(0,0,0);
	vec3 colSpecular = vec3(0,0,0);

	// Переводим нормаль из локальной в глобальную систему координат
	vec3 vertexNormal = (vec4(localNormal, 0.0) * matWorldNormal).xyz;
	vertexNormal = normalize(vertexNormal);
	
	// Переводим позицию из локальной в глобальную систему координат
	vec3 vertexPos = (vec4(localPosition, 1.0) * matWorldT).xyz;
	vec3 cameraPos = vec3(matViewInversed[3]);
	vec3 fragmentToCamera = normalize(cameraPos - vertexPos);
	vec3 normal  = normalize(vertexNormal);
	
	for (int i = 0; i < 3; ++i)
	{
		// Выходим, как только закончились источники освещения
                if (float(i) >= lightsCount.x) break;
		
		float type = lights[i].type.x;
		float epsilon = 0.001;
		float attenuationFactor;
		float spotFactor;
		
		vec4 lightCol = lights[i].color;
		vec3 lightColSpecular = vec3(1,1,1);
		vec3 lightDir = vec3(0,0,0);
	
		// Directional light
                if (abs(type - 1.0) < epsilon)
		{
			lightDir = normalize(lights[i].direction.xyz).xyz;
			attenuationFactor = 1.0;
			spotFactor = 1.0;
		}
		// Point light
                else if (abs(type - 2.0) < epsilon)
		{
			lightDir = normalize(vertexPos - lights[i].position.xyz).xyz;
			attenuationFactor = calcLightAttenuation(vertexPos, lights[i].position);
			spotFactor = 1.0;
		}
		// Spot light
		        else if (abs(type - 3.0) < epsilon)
		{
		    lightDir = normalize(vertexPos - lights[i].position.xyz).xyz;
		    attenuationFactor = 1.0;
            spotFactor = calcSpotLight(normal, fragmentToCamera, lights[i], vertexPos);
		}
		
		colDiffuse += attenuationFactor * spotFactor * materialColor.rgb * calcDiffuse(lightCol, lightDir, vertexNormal);
		colSpecular += calcSpecular(fragmentToCamera, lightDir, normal, lightColSpecular);
	}
	colSpecular *= materialColor.rgb;
	col = colSpecular + colDiffuse;
	gl_FragColor = vec4(col, 1.0);
        gl_FragColor.a = 1.0;
}
