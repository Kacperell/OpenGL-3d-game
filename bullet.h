#include "gameobject.h"
#include "cmesh.h"
class Bullet : public GameObject
{
public:
 Bullet();
 void init();
 void render(GLWidget* glwidget);
 void update();
 CMesh *m_mesh;
};
