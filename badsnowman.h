#ifndef BADSNOWMAN_H
#define BADSNOWMAN_H

#include "gameobject.h"
#include "cmesh.h"
class badSnowman : public GameObject
{
public:
     badSnowman();
     void init();
    void render(GLWidget* glwidget);
    void update();
    void shadow(GLWidget* glwidget);

    CMesh *m_mesh;
};

#endif // BADSNOWMAN_H
