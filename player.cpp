#include "player.h"

Player::Player()
{
    position =QVector3D(0,0,0);
    direction=QVector3D(0,0,-1);
    speed=0.01f;
}

void Player::init()
{
    m_mesh = CMesh::m_meshes["bunny"];

    m_name = "Player";
    scale = QVector3D(0.0045f, 0.0045f, 0.0045f);
    m_radius = 0.1f;
    material.diffuse.setX( 0.5f);
   material.diffuse.setY(2.1f);
    material.diffuse.setZ(0.7f);

    zab=0;
}

void Player::render(GLWidget* glwidget)
{
    m_mesh->render(glwidget);

}

void Player::update()
{
    rotation.setY(90-atan2(direction.z(), direction.x()) * 180 / 3.14f);
    // wykorzystanie energii.
    position = position + energy;
    // wytracanie energii.
    energy = energy / 1.2f;

}
