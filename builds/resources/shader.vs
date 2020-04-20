attribute vec4 vertex;
attribute vec3 normal;
attribute vec2 uvCoord;
uniform mat4 projMatrix;
uniform mat4 viewMatrix;
uniform mat4 modelMatrix;
uniform highp int hasTexture;
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

void main() {
    fragNormal = normal;
    fragUV = uvCoord;
    vertexWorldSpace = (modelMatrix * vertex).xyz;
    gl_Position = projMatrix * viewMatrix * modelMatrix * vertex;
}
