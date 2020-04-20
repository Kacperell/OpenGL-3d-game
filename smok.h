#ifndef SMOK_H
#define SMOK_H


#include "gameobject.h"
#include "cmesh.h"
class smok : public GameObject
{
public:
     smok();
     void init();
    void render(GLWidget* glwidget);
    void update();
    void shadow(GLWidget* glwidget);

    CMesh *m_mesh;
};

#endif // SMOK_H

