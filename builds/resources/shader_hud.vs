attribute vec4 vertex;
attribute vec3 normal;
attribute vec2 uvCoord;
uniform highp vec3 color;
uniform highp int hasTexture;
uniform sampler2D texture;
uniform highp vec2 resolution;
varying vec2 fragUV;


struct Rectangle
{
    float xPos;
    float yPos;
    float width;
    float height;
};

uniform Rectangle rect;
void main()
{
    fragUV = uvCoord;
    gl_Position.x = (rect.xPos + rect.width * vertex.x) / resolution.x * 2.0 - 1.0;
    gl_Position.y = (rect.yPos + rect.height * vertex.y) / resolution.y * (-2.0) + 1.0;
    gl_Position.z = 0.0;
    gl_Position.w = 1.0;
}
