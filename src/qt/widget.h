#ifndef WIDGET_H
#define WIDGET_H

#include <QMatrix4x4>
#include <QMouseEvent>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>
#include <QQuaternion>
// #include <QRectf>
#include <QTimer>
#include <QWidget>

#include "geometry.h"

class GeometryEngine;

// QT_BEGIN_NAMESPACE
// namespace Ui {class Widget; }
// QT_END_NAMESPACE

class Widget : public QOpenGLWidget, protected QOpenGLFunctions {
  Q_OBJECT

 public:
  //    Widget(QWidget *parent = nullptr);
  //    QString filepath;
  using QOpenGLWidget::QOpenGLWidget;
  QColor *color = new QColor(255, 249, 0, 0);
  QColor *color_back = new QColor(182, 0, 255, 255);
  QColor *color_ver = new QColor(17, 242, 0, 255);
  int line_width = 1;
  int vertex_size = 0;
  int flag_dotted = 0;
  int projection_ortho = 0;
  int flag_ver = 0;
  int flag_sphere = 0;
  ~Widget();
  GeometryEngine *geometries = nullptr;
  QOpenGLShaderProgram program;
  void initColors();
  void initColorsVer();
  void updating();
  void paintGL() override;
  void resizeGL(int w, int h) override;

 protected:
  void mousePressEvent(QMouseEvent *) override;
  void mouseMoveEvent(QMouseEvent *) override;
  void timerEvent(QTimerEvent *) override;

  void initShaders();

  void initializeGL() override;

 private:
  QBasicTimer timer;
  QMatrix4x4 projection;
  QQuaternion rotation;
  float xRot, yRot, zRot;
  QPoint mPos;
  QTimer tmr;
  QVector2D mousePressPosition;
  QVector3D rotationAxis;
  qreal angularSpeed = 0;
};

#endif  // WIDGET_H
