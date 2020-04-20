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
     highp vec4 tex = texture2D(texture, fragUV).xyzw;
     if(hasTexture == 1)
         gl_FragColor = vec4(color * tex.xyz, tex.w);
     else
         gl_FragColor = vec4(color, 1.0);
}
