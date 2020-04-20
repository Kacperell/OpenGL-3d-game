uniform int hasTexture;
uniform sampler2D texture;
uniform highp vec3 cameraPosition;
varying highp vec3 fragNormal;
varying highp vec3 vertexWorldSpace;
varying highp vec2 fragUV;

const int MAX_LIGHTS = 5;

struct Light {
    highp vec3 position;
    highp vec3 ambient;
    highp vec3 diffuse;
    highp vec3 specular;
    int isActive;
    float attenuation;
};
uniform Light light[MAX_LIGHTS];

struct Material
{
    highp vec3 ambient;
    highp vec3 diffuse;
    highp vec3 specular;
    highp float shininess;
};

uniform Material material;

void main()
{
    highp vec3 tex = texture2D(texture, fragUV).xyz;
    highp vec3 colorFull = vec3(0,0,0);
    highp vec3 N = normalize(fragNormal);
    highp vec3 V = normalize(vertexWorldSpace - cameraPosition);

    for(int i = 0; i<MAX_LIGHTS; i++)
    {
        if(light[i].isActive == 1)
        {
            highp vec3 L = normalize(light[i].position - vertexWorldSpace);
            highp vec3 H = normalize(L + V);
            highp float D = length(light[i].position-vertexWorldSpace);

            highp float cosNL = dot(N, L);
            cosNL = clamp(cosNL, 0.0, 1.0);

            highp float cosVH = dot(V, H);
            cosVH = clamp(cosVH, 0.0, 1.0);

            highp vec3 colorAmb = material.ambient * light[i].ambient;
            highp vec3 colorDif = material.diffuse * light[i].diffuse * cosNL;
            highp vec3 colorSpe = material.specular * light[i].specular * pow(cosVH, material.shininess);
            if(hasTexture == 1)
            {
                colorAmb = colorAmb * tex;
                colorDif = colorDif * tex;
            }
            colorAmb = colorAmb / pow(D, light[i].attenuation);
            colorDif = colorDif / pow(D, light[i].attenuation);
            colorSpe = colorSpe / pow(D, light[i].attenuation);
            colorFull = clamp(colorFull + colorAmb + colorDif + colorSpe, 0.0, 1.0);
        }
    }
    gl_FragColor = vec4(colorFull, 1.0);
}
