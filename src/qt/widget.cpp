#include "widget.h"
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QVector>
#include <QMouseEvent>

#ifdef __cplusplus
extern "C" {
#include "../parse.h"
}
#endif


//Widget::Widget(QWidget *parent)
//    : QOpenGLWidget(parent)
//{
//    setWindowTitle("alala");
//    setGeometry(400, 200, 800, 600);
//    makeCurrent();
//    delete geometries;
//    doneCurrent();
//}

Widget::~Widget()
{
    makeCurrent();
    delete geometries;
    doneCurrent();
}

void Widget::mousePressEvent(QMouseEvent * mo)
{
//    mPos = mo->pos();
//    float data[72];
//    for (int i = 0; i < 72; i++) {
//        data[i] = 1.0 / (arc4random() % 20);
//    }
//    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(data), data);
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
//    update();
//    mousePressPosition = QVector2D(mo->position());
}

void Widget::mouseMoveEvent(QMouseEvent* mo)
{
//    xRot = 1 / M_PI * (mo->pos().y() - mPos.y());
//    yRot = 1 / M_PI * (mo->pos().x() - mPos.x());
//    update();
//     Mouse release position - mouse press position
//    QVector2D diff = QVector2D(mo->position()) - mousePressPosition;

//    // Rotation axis is perpendicular to the mouse position difference
//    // vector
//    QVector3D n = QVector3D(diff.y(), diff.x(), 0.0).normalized();

//    // Accelerate angular speed relative to the length of the mouse sweep
//    qreal acc = diff.length() / 100.0;

//    // Calculate new rotation axis as weighted sum
//    rotationAxis = (rotationAxis * angularSpeed + n * acc).normalized();

//    // Increase angular speed
//    angularSpeed += acc;
}

void Widget::timerEvent(QTimerEvent *)
{
//    // Decrease angular speed (friction)
//    angularSpeed *= 0.9;

//    // Stop rotation when speed goes below threshold
//    if (angularSpeed < 0.01) {
//        angularSpeed = 0.0;
//    } else {
//        // Update rotation
//        rotation = QQuaternion::fromAxisAndAngle(rotationAxis, angularSpeed) * rotation;

//        // Request an update
////        update();
//    }
}


void Widget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0, 0, 0, 1);
    initShaders();

    glEnable(GL_DEPTH_TEST);

    glEnable(GL_CULL_FACE);

    geometries = new GeometryEngine;
    timer.start(120, this);
}

void Widget::initShaders()
{
    if (!program.addShaderFromSourceFile(QOpenGLShader::Vertex, ":vshader.glsl"))
        close();


    if (!program.addShaderFromSourceFile(QOpenGLShader::Fragment, ":fshader.glsl"))
        close();

    if(!program.link())
        close();

    if(!program.bind())
        close();
}

void Widget::initColors() {
    glClearColor(color_back->redF(), color_back->greenF(), color_back->blueF(), 0);

    int vertexLocation = program.attributeLocation("vertex");
    int colorLocation = program.uniformLocation("color");

    program.enableAttributeArray(vertexLocation);
    program.setUniformValue(colorLocation, *color);
    program.disableAttributeArray(vertexLocation);
}

void Widget::initColorsVer() {
//    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(color_back->redF(), color_back->greenF(), color_back->blueF(), 0);

//    color_ver->setRgb(0,0,0);

    int vertexLocation = program.attributeLocation("vertex");
    int colorLocation = program.uniformLocation("color");

    program.enableAttributeArray(vertexLocation);
    program.setUniformValue(colorLocation, *color_ver);
    program.disableAttributeArray(vertexLocation);
}

void Widget::updating()
{
    update();
}

void Widget::resizeGL(int w, int h)
{
    float aspect = qreal(w) / qreal(h ? h : 1);
    projection.setToIdentity();
    if (this->projection_ortho == 1) {
        QRectF orthoRectangle;
        orthoRectangle.setHeight(h);
        orthoRectangle.setWidth(w);
        projection.ortho(-10.0, 10.0, -10.0, 10.0, -50, 50);
    } else {
        projection.perspective(45.0, aspect, 0.5, 7.8);
    }
}

void Widget::paintGL()
{
    glLineWidth(line_width);

    initColors();

    geometries->flag_sphere = this->flag_sphere;
    geometries->flag_ver = this->flag_ver;
    geometries->size_ver = this->vertex_size;

    QMatrix4x4 matrix;
    matrix.translate(0.0, 0.0, -5.0);
    matrix.rotate(rotation);

    program.setUniformValue("mvp_matrix", projection * matrix);

    if (flag_dotted) {
        glEnable(GL_LINE_SMOOTH);
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(2, 58360);
        geometries->drawprocess(&program);
        glDisable(GL_LINE_SMOOTH);
        glDisable(GL_LINE_STIPPLE);
    } else {
         geometries->drawprocess(&program);
    }

//    program.setUniformValue("texture", 0);
    initColorsVer();
    geometries->drawdot(&program);
    update();
}


