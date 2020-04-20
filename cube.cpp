#include "gameobject.h"
#include "cmesh.h"
#include "cube.h"

Cube::Cube()
{
    m_name = "cube";
}

void Cube::init()
{
     m_mesh = CMesh::m_meshes["cube"];
}

void Cube::render(GLWidget* glwidget)
{
    m_mesh->render(glwidget);
}

void Cube::update()
{
    // wykorzystanie energii.
  //ww  position = position + energy;
    // wytracanie energii.
    // energy = energy / 1.2f;
}
