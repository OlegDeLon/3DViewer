#include "geometry.h"

#include <QVector2D>
#include <QVector3D>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QVector>

#ifdef __cplusplus
extern "C" {
#include "../parse.h"
#include "../afini.h"
}
#endif

struct VertexData
{
    QVector3D position;
};

data_d data;
data_d *pdata = &data;
array_d arrays;
array_d *p_arrays = &arrays;

GeometryEngine::GeometryEngine()
    : indexBuf(QOpenGLBuffer::IndexBuffer)
{
    initializeOpenGLFunctions();
    arrayBuf.create();
    indexBuf.create();

    parsing();
}

GeometryEngine::~GeometryEngine()
{

    arrayBuf.destroy();
    indexBuf.destroy();
}

void GeometryEngine::parsing()
{
    if (this->filepath == "") {
        return;
    }
        pdata->count_of_vertexes = 0;
        pdata->count_of_facets = 0;
        pdata->count_of_facets_all = 0;
        QFile inputFile(QString(this->filepath));
        inputFile.open(QIODevice::ReadOnly);
        QTextStream stream(&inputFile);
        for (QString line = stream.readLine();!line.isNull();line = stream.readLine()) {
            QByteArray string = line.toLocal8Bit();
             char* str = string.data();
            parse1(pdata, str);
        }
        inputFile.close();
        arrays.n = pdata->count_of_vertexes * 3;
        arrays.vertexesarray = (float *)malloc(arrays.n * sizeof(float));

        arrays.b = pdata->count_of_facets_all * 2;
        arrays.facetsarray = (int *)malloc(arrays.b * sizeof(int));
        arrays.fcount = 0;
        arrays.vcount = 0;


        QFile inputFile2(QString(this->filepath));
        inputFile2.open(QIODevice::ReadOnly);
        QTextStream stream2(&inputFile2);
        for (QString line = stream2.readLine();!line.isNull();line = stream2.readLine()) {
            QByteArray string = line.toLocal8Bit();
             char *str = string.data();
             parse2(p_arrays, str);
        }
        inputFile2.close();

//        QVector<VertexData> vertices;

//        for (int i = 0, j = 0; i < arrays.n; i+=3, j++) {
//            VertexData tmp_vert = {QVector3D(arrays.vertexesarray[i], arrays.vertexesarray[i+1], arrays.vertexesarray[i+2])};
//            vertices.push_back(tmp_vert);
//        }
        binding();
        QVector<GLuint> indices;
        for (int i = 0; i < arrays.b; i++) {
            indices.push_back(arrays.facetsarray[i]);
        }

//        free(arrays.vertexesarray);
        free(arrays.facetsarray);

        lines = indices.length();

//        arrayBuf.bind();
//        arrayBuf.allocate(vertices.data(), sizeof(VertexData) * vertices.length());

        indexBuf.bind();
        indexBuf.allocate(indices.data(), sizeof(GLuint)*indices.length());

}

void GeometryEngine::scaling(double value)
{
    if (value != 0.0) {
        scale(p_arrays, value / new_scale);
        new_scale = value;
    }
}

void GeometryEngine::moving_x(double value_x)
{
    if (value_x != 0.0) {
        move_x(p_arrays, value_x - new_move_x);
        new_move_x = value_x;
    }
}

void GeometryEngine::moving_y(double value_y)
{
    if (value_y != 0.0) {
        move_y(p_arrays, value_y - new_move_y);
        new_move_y = value_y;
    }
}

void GeometryEngine::moving_z(double value_z)
{
    if (value_z != 0.0) {
        move_z(p_arrays, value_z - new_move_z);
        new_move_z = value_z;
    }
}

void GeometryEngine::rotating_x(double value_x)
{
    if (value_x != 0.0) {
        rotation_by_ox(p_arrays, value_x - new_rotate_x);
        new_rotate_x = value_x;
    }
}

void GeometryEngine::rotating_y(double value_y)
{
    if (value_y != 0.0) {
        rotation_by_oy(p_arrays, value_y - new_rotate_y);
        new_rotate_y = value_y;
    }
}

void GeometryEngine::rotating_z(double value_z)
{
    if (value_z != 0.0) {
        rotation_by_oz(p_arrays, value_z - new_rotate_z);
        new_rotate_z = value_z;
    }
}

void GeometryEngine::binding()
{
    QVector<VertexData> vertices;

    for (int i = 0, j = 0; i < arrays.n; i+=3, j++) {
        VertexData tmp_vert = {QVector3D(arrays.vertexesarray[i], arrays.vertexesarray[i+1], arrays.vertexesarray[i+2])};
        vertices.push_back(tmp_vert);
    }

    arrayBuf.bind();
    arrayBuf.allocate(vertices.data(), sizeof(VertexData) * vertices.length());
}

void GeometryEngine::drawprocess(QOpenGLShaderProgram *program)
{
    binding();
    arrayBuf.bind();
    indexBuf.bind();
//    arrayBuf.bind();
    quintptr offset = 0;

    int vertexLocation = program->attributeLocation("a_position");
    program->enableAttributeArray(vertexLocation);
    program->setAttributeBuffer(vertexLocation, GL_FLOAT, offset, 3, sizeof(VertexData));

    offset += sizeof(QVector3D);

    // Tell OpenGL programmable pipeline how to locate vertex texture coordinate data
    int texcoordLocation = program->attributeLocation("a_texcoord");
    program->enableAttributeArray(texcoordLocation);
    program->setAttributeBuffer(texcoordLocation, GL_FLOAT, offset, 2, sizeof(VertexData));
    if (flag_for_to_draw == 1) {
        glDrawElements(GL_LINES, lines, GL_UNSIGNED_INT, nullptr);
    }
}

void GeometryEngine::drawdot(QOpenGLShaderProgram *program)
{

    if (!flag_ver) return;
        if (flag_sphere) {
            glDisable(GL_POINT_SIZE);
            glEnable(GL_POINT_SMOOTH);
        } else {
            glDisable(GL_POINT_SMOOTH);
            glEnable(GL_POINT_SIZE);
        }

        glPointSize(size_ver);

        binding();
        arrayBuf.bind();
        indexBuf.bind();
//        arrayBuf.bind();
        quintptr offset = 0;

        int vertexLocation = program->attributeLocation("a_position");
        program->enableAttributeArray(vertexLocation);
        program->setAttributeBuffer(vertexLocation, GL_FLOAT, offset, 3, sizeof(VertexData));

        offset += sizeof(QVector3D);

        // Tell OpenGL programmable pipeline how to locate vertex texture coordinate data
        int texcoordLocation = program->attributeLocation("a_texcoord");
        program->enableAttributeArray(texcoordLocation);
        program->setAttributeBuffer(texcoordLocation, GL_FLOAT, offset, 2, sizeof(VertexData));

        if (flag_for_to_draw == 1) {
            glDrawElements(GL_POINTS, lines, GL_UNSIGNED_INT, nullptr);
        }
}


