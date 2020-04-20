#ifndef CMesh_H
#define CMesh_H

#include <qopengl.h>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QVector>
#include <QVector2D>
#include <QVector3D>

class GLWidget;

class CMesh
{
public:
    CMesh();
    ~CMesh();
    const GLfloat *constData() const { return m_data.constData(); }
    int vertexCount() const { return m_count; }
    GLenum primitive() {return m_primitive; }

    void generateCube(GLfloat ww, GLfloat hh, GLfloat dd);
    void generateSphere(float r, int N);
    void generateRectangle();
    void generateMeshFromObjFile(QString filename);

    void initVboAndVao();

    void render(GLWidget* glWidget);
    void render(GLWidget* glWidget, int offset, int count);
    static std::map<std::string, CMesh*> m_meshes;
    static void loadAllMeshes();
    GLenum m_primitive;
    void add(const QVector3D &v, const QVector3D &n, const QVector2D &uv);
private:

    void quad3(GLfloat x1, GLfloat y1, GLfloat z1,
               GLfloat x2, GLfloat y2, GLfloat z2,
               GLfloat x3, GLfloat y3, GLfloat z3,
               GLfloat x4, GLfloat y4, GLfloat z4);

    QVector<GLfloat> m_data;
    int m_count;

    QOpenGLVertexArrayObject m_vao;
    QOpenGLBuffer m_vbo;
    QOpenGLVertexArrayObject::Binder* m_vao_binder;
};

#endif // CMesh_H

