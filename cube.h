#include "gameobject.h"
#include "cmesh.h"
class Cube : public GameObject
{
public:
     Cube();
     void init();
    void render(GLWidget* glwidget);
    void update();
    CMesh *m_mesh;
};
