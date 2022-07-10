#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <qmath.h>
#include <QColor>

extern "C" {
#include "../parse.h"
#include "../afini.h"
}

class GeometryEngine : public QOpenGLFunctions {
    struct VertexData {
      QVector3D position;
    };

 public:
  int flag_for_update_massive = 0;
  int flag_for_to_draw = 0;
  int flag_ver = 0;
  int flag_sphere = 0;
  int size_ver = 2;
  double new_scale = 1;
  double new_move_x = 0;
  double new_move_y = 0;
  double new_move_z = 0;
  double new_rotate_x = 0;
  double new_rotate_y = 0;
  double new_rotate_z = 0;
  QString filepath;
  GeometryEngine();
  virtual ~GeometryEngine();

  void drawprocess(QOpenGLShaderProgram *program);
  void drawdot(QOpenGLShaderProgram *program);
  void parsing();
  void scaling(double value);
  void moving_x(double value_x);
  void moving_y(double value_y);
  void moving_z(double value_z);
  void rotating_x(double value_x);
  void rotating_y(double value_y);
  void rotating_z(double value_z);
  void binding();

 private:
  QOpenGLBuffer arrayBuf;
  QOpenGLBuffer indexBuf;

  GLsizei lines;
};


#endif // GEOMETRY_H
