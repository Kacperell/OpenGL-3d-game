#include "texturemanager.h"
#include <map>
#include <string>
#include <QOpenGLTexture>

std::map<std::string, QOpenGLTexture*> TextureManager::m_textures;

TextureManager::TextureManager()
{

}

void TextureManager::init()
{

    m_textures["grass"] = new QOpenGLTexture(QImage("resources/las2.jpg"));
    m_textures["wood"] = new QOpenGLTexture(QImage("resources/wood.jpg"));
    m_textures["tr"] = new QOpenGLTexture(QImage("resources/trawa.jpg"));
    m_textures["las"] = new QOpenGLTexture(QImage("resources/las2.jpg"));
     m_textures["luski"] = new QOpenGLTexture(QImage("resources/luski.jpg"));
}

QOpenGLTexture* TextureManager::getTexture(std::string name)
{
    return m_textures[name];
}
