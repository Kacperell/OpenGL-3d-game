#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <vector>
#include <QElapsedTimer>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QMatrix4x4>
#include <QKeyEvent>
#include <QMap>
#include "cmesh.h"
#include "player.h"
QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = nullptr);
    ~GLWidget();

    QSize sizeHint() const override;

    friend CMesh;

public slots:
    void cleanup();

signals:

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void updateGL();
    void paintHUD();
    void paintHUDWIN();
    void setTransforms(void);
    void qNormalizeAngle(float &angle);
    void addObject(GameObject* obj);
    void initCollisionTriangles();
    void addTriangleCollider();
private:

    struct LightLocStruct
    {
        int position;
        int ambient;
        int diffuse;
        int specular;
        int isActive;
        int attenuation;
    };

    struct MaterialLocStruct
    {
        int ambient;
        int diffuse;
        int specular;
        int shininess;
    };

    struct RectangleLocStruct
    {
        int xPos;
        int yPos;
        int width;
        int height;
    };

    struct Light
    {
        QVector3D position;
        QVector3D ambient;
        QVector3D diffuse;
        QVector3D specular;
        bool isActive = false;
        float attenuation;
    };

    static const int MAX_LIGHTS = 5;

    Light m_lights[MAX_LIGHTS];
    void setLights();

    QPoint m_lastPos;
    QOpenGLShaderProgram *m_program;
    int m_projMatrixLoc;
    int m_viewMatrixLoc;
    int m_modelMatrixLoc;
    //int m_modelColorLoc;
    int m_hasTextureLoc;
    int m_cameraPositionLoc;
    LightLocStruct m_lightLoc[MAX_LIGHTS];
    MaterialLocStruct m_materialLoc;

    QOpenGLShaderProgram *m_program_hud;
    int m_resolutionLoc_hud;
    int m_color_hud;
    int m_hasTextureLoc_hud;
    RectangleLocStruct m_rectangleLoc_hud;
    void setRectangle(float xPos, float yPos, float width, float height, QVector3D color, QOpenGLTexture *texture);
    QVector2D m_resolution;

    QMatrix4x4 m_proj;
    QMatrix4x4 m_camera;
    QMatrix4x4 m_world;

    bool m_keyState[256] ={0};

    float m_camDistance = 1.5f;

    QElapsedTimer timer;
    float lastUpdateTime;
    float FPS = 60;

    struct Triangle
    {
        QVector3D v1, v2, v3;
        QOpenGLTexture* texture;
        QVector3D n;
        float A,B,C,D;
        int groupSize;
    };

    std::vector<Triangle> collisionTriangles;
    CMesh collisionTriangleMesh;
    void addTriangleCollider(QVector3D v1, QVector3D v2, QVector3D v3, int groupSize = 1,
                             QVector2D uv1 = QVector2D(0,0), QVector2D uv2 = QVector2D(0,0),
                             QVector2D uv3 = QVector2D(0,0), QOpenGLTexture* texture = nullptr);


    Player m_player;
    //mouse
    std::vector<GameObject*> m_gameObjects;

};

#endif

