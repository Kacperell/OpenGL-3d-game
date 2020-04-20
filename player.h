#include "gameobject.h"
#include "cmesh.h"
#include <math.h>
class Player : public GameObject
{
public:
 Player();
 QVector3D direction;
 float speed;
 void init();
 void render(GLWidget* glwidget);
 void update();
 CMesh *m_mesh;
 int zab;
};
