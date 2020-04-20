#include "smok.h"
#include "gameobject.h"
#include "cmesh.h"


#include <iostream>
smok::smok()
{
    m_name = "smok";

}




void smok::init()
{
     m_mesh = CMesh::m_meshes["smok"];
}

void smok::render(GLWidget* glwidget)
{
    m_mesh->render(glwidget);
}

void smok::update()
{

    position = position + energy;


     energy = energy / 1.2f;
      // energy = energy / 1.1f;



}

void smok::shadow(GLWidget* glwidget)
{

}





