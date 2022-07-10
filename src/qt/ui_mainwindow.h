/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <widget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    Widget *openGLWidget;
    QLabel *filename;
    QLabel *vertexes;
    QLabel *facets;
    QPushButton *openfile;
    QPushButton *GIF;
    QPushButton *screenshot;
    QPushButton *move;
    QSlider *move_x_Slider;
    QSlider *move_y_Slider;
    QSlider *move_z_Slider;
    QSlider *rotation_y_Slider;
    QPushButton *rotation;
    QSlider *rotation_z_Slider;
    QSlider *rotation_x_Slider;
    QLabel *move_x;
    QLabel *move_y;
    QLabel *move_z;
    QLabel *rotation_x;
    QLabel *rotation_y;
    QLabel *rotation_z;
    QPushButton *scale;
    QSlider *scale_Slider;
    QLabel *vertexes_2;
    QPushButton *color_back;
    QLabel *vertexes_5;
    QPushButton *color_lines;
    QLabel *vertexes_6;
    QPushButton *color_vertexes;
    QLabel *projection_view;
    QLabel *lines_view;
    QRadioButton *centre;
    QRadioButton *continuous;
    QRadioButton *parallel;
    QRadioButton *dotted_line;
    QSpinBox *spinBox_linethickness;
    QLabel *formvertexes;
    QLabel *line_thickness;
    QSpinBox *spinBox_size_vertexes;
    QLabel *size_vertexes;
    QPushButton *apply_line;
    QPushButton *apply_vertexes;
    QPushButton *apply_projection;
    QPushButton *apply_vid_line;
    QDoubleSpinBox *scale_2;
    QDoubleSpinBox *rotate_z;
    QDoubleSpinBox *rotate_x;
    QDoubleSpinBox *rotate_y;
    QDoubleSpinBox *move_z_2;
    QDoubleSpinBox *move_y_2;
    QDoubleSpinBox *move_x_2;
    QPushButton *default_2;
    QRadioButton *no_vertex;
    QRadioButton *round_vertex;
    QRadioButton *square_vertex;
    QPushButton *apply_vertex_type;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QButtonGroup *buttonGroup;
    QButtonGroup *buttonGroup_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1033, 901);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        openGLWidget = new Widget(centralwidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setGeometry(QRect(0, 0, 640, 480));
        filename = new QLabel(centralwidget);
        filename->setObjectName(QString::fromUtf8("filename"));
        filename->setGeometry(QRect(15, 483, 281, 21));
        QFont font;
        font.setPointSize(15);
        filename->setFont(font);
        filename->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(255, 255, 255);\n"
"  border: 1px solid rgb(0, 0, 0);\n"
"}"));
        vertexes = new QLabel(centralwidget);
        vertexes->setObjectName(QString::fromUtf8("vertexes"));
        vertexes->setGeometry(QRect(349, 482, 131, 21));
        vertexes->setFont(font);
        vertexes->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(255, 255, 255);\n"
"  border: 1px solid rgb(0, 0, 0);\n"
"}"));
        facets = new QLabel(centralwidget);
        facets->setObjectName(QString::fromUtf8("facets"));
        facets->setGeometry(QRect(510, 480, 131, 21));
        facets->setFont(font);
        facets->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(255, 255, 255);\n"
"  border: 1px solid rgb(0, 0, 0);\n"
"}"));
        openfile = new QPushButton(centralwidget);
        openfile->setObjectName(QString::fromUtf8("openfile"));
        openfile->setGeometry(QRect(10, 518, 151, 54));
        openfile->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color:rgb(157, 104, 255);\n"
"  color: rgb(255, 255, 255); \n"
"  border: 1px solid rgb(157, 104, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"       background-color: rgb(112, 70, 183);\n"
" border: 1px solid rgb(0, 0, 0);\n"
"}"));
        GIF = new QPushButton(centralwidget);
        GIF->setObjectName(QString::fromUtf8("GIF"));
        GIF->setGeometry(QRect(180, 580, 151, 54));
        GIF->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color:rgb(157, 104, 255);\n"
"  color: rgb(255, 255, 255); \n"
"  border: 1px solid rgb(157, 104, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"       background-color: rgb(112, 70, 183);\n"
" border: 1px solid rgb(0, 0, 0);\n"
"}"));
        screenshot = new QPushButton(centralwidget);
        screenshot->setObjectName(QString::fromUtf8("screenshot"));
        screenshot->setGeometry(QRect(180, 518, 151, 54));
        screenshot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color:rgb(157, 104, 255);\n"
"  color: rgb(255, 255, 255); \n"
"  border: 1px solid rgb(157, 104, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"       background-color: rgb(112, 70, 183);\n"
" border: 1px solid rgb(0, 0, 0);\n"
"}"));
        move = new QPushButton(centralwidget);
        move->setObjectName(QString::fromUtf8("move"));
        move->setGeometry(QRect(650, 120, 381, 41));
        move->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color:rgb(157, 104, 255);\n"
"  color: rgb(255, 255, 255); \n"
"  border: 1px solid rgb(157, 104, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"       background-color: rgb(112, 70, 183);\n"
" border: 1px solid rgb(0, 0, 0);\n"
"}"));
        move_x_Slider = new QSlider(centralwidget);
        move_x_Slider->setObjectName(QString::fromUtf8("move_x_Slider"));
        move_x_Slider->setGeometry(QRect(760, 10, 271, 25));
        move_x_Slider->setMinimum(-500);
        move_x_Slider->setMaximum(500);
        move_x_Slider->setOrientation(Qt::Horizontal);
        move_x_Slider->setTickPosition(QSlider::NoTicks);
        move_y_Slider = new QSlider(centralwidget);
        move_y_Slider->setObjectName(QString::fromUtf8("move_y_Slider"));
        move_y_Slider->setGeometry(QRect(760, 50, 271, 25));
        move_y_Slider->setMinimum(-500);
        move_y_Slider->setMaximum(500);
        move_y_Slider->setOrientation(Qt::Horizontal);
        move_y_Slider->setTickPosition(QSlider::NoTicks);
        move_z_Slider = new QSlider(centralwidget);
        move_z_Slider->setObjectName(QString::fromUtf8("move_z_Slider"));
        move_z_Slider->setGeometry(QRect(760, 90, 271, 25));
        move_z_Slider->setMinimum(-500);
        move_z_Slider->setMaximum(500);
        move_z_Slider->setOrientation(Qt::Horizontal);
        move_z_Slider->setTickPosition(QSlider::NoTicks);
        rotation_y_Slider = new QSlider(centralwidget);
        rotation_y_Slider->setObjectName(QString::fromUtf8("rotation_y_Slider"));
        rotation_y_Slider->setGeometry(QRect(760, 213, 271, 25));
        rotation_y_Slider->setMinimum(-500);
        rotation_y_Slider->setMaximum(500);
        rotation_y_Slider->setOrientation(Qt::Horizontal);
        rotation_y_Slider->setTickPosition(QSlider::NoTicks);
        rotation = new QPushButton(centralwidget);
        rotation->setObjectName(QString::fromUtf8("rotation"));
        rotation->setGeometry(QRect(650, 290, 381, 41));
        rotation->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color:rgb(157, 104, 255);\n"
"  color: rgb(255, 255, 255); \n"
"  border: 1px solid rgb(157, 104, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"       background-color: rgb(112, 70, 183);\n"
" border: 1px solid rgb(0, 0, 0);\n"
"}"));
        rotation_z_Slider = new QSlider(centralwidget);
        rotation_z_Slider->setObjectName(QString::fromUtf8("rotation_z_Slider"));
        rotation_z_Slider->setGeometry(QRect(760, 253, 271, 25));
        rotation_z_Slider->setMinimum(-500);
        rotation_z_Slider->setMaximum(500);
        rotation_z_Slider->setOrientation(Qt::Horizontal);
        rotation_z_Slider->setTickPosition(QSlider::NoTicks);
        rotation_x_Slider = new QSlider(centralwidget);
        rotation_x_Slider->setObjectName(QString::fromUtf8("rotation_x_Slider"));
        rotation_x_Slider->setGeometry(QRect(760, 173, 271, 25));
        rotation_x_Slider->setMinimum(-500);
        rotation_x_Slider->setMaximum(500);
        rotation_x_Slider->setOrientation(Qt::Horizontal);
        rotation_x_Slider->setTickPosition(QSlider::NoTicks);
        move_x = new QLabel(centralwidget);
        move_x->setObjectName(QString::fromUtf8("move_x"));
        move_x->setGeometry(QRect(650, 10, 31, 21));
        move_x->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(255, 255, 255);\n"
"  border: 1px solid rgb(0, 0, 0);\n"
"}"));
        move_y = new QLabel(centralwidget);
        move_y->setObjectName(QString::fromUtf8("move_y"));
        move_y->setGeometry(QRect(650, 50, 31, 21));
        move_y->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(255, 255, 255);\n"
"  border: 1px solid rgb(0, 0, 0);\n"
"}"));
        move_z = new QLabel(centralwidget);
        move_z->setObjectName(QString::fromUtf8("move_z"));
        move_z->setGeometry(QRect(650, 89, 31, 21));
        move_z->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(255, 255, 255);\n"
"  border: 1px solid rgb(0, 0, 0);\n"
"}"));
        rotation_x = new QLabel(centralwidget);
        rotation_x->setObjectName(QString::fromUtf8("rotation_x"));
        rotation_x->setGeometry(QRect(650, 172, 31, 21));
        rotation_x->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(255, 255, 255);\n"
"  border: 1px solid rgb(0, 0, 0);\n"
"}"));
        rotation_y = new QLabel(centralwidget);
        rotation_y->setObjectName(QString::fromUtf8("rotation_y"));
        rotation_y->setGeometry(QRect(650, 212, 31, 21));
        rotation_y->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(255, 255, 255);\n"
"  border: 1px solid rgb(0, 0, 0);\n"
"}"));
        rotation_z = new QLabel(centralwidget);
        rotation_z->setObjectName(QString::fromUtf8("rotation_z"));
        rotation_z->setGeometry(QRect(650, 251, 31, 21));
        rotation_z->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(255, 255, 255);\n"
"  border: 1px solid rgb(0, 0, 0);\n"
"}"));
        scale = new QPushButton(centralwidget);
        scale->setObjectName(QString::fromUtf8("scale"));
        scale->setGeometry(QRect(650, 390, 381, 41));
        scale->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color:rgb(157, 104, 255);\n"
"  color: rgb(255, 255, 255); \n"
"  border: 1px solid rgb(157, 104, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"       background-color: rgb(112, 70, 183);\n"
" border: 1px solid rgb(0, 0, 0);\n"
"}"));
        scale_Slider = new QSlider(centralwidget);
        scale_Slider->setObjectName(QString::fromUtf8("scale_Slider"));
        scale_Slider->setGeometry(QRect(760, 350, 271, 25));
        scale_Slider->setLayoutDirection(Qt::LeftToRight);
        scale_Slider->setMaximum(200);
        scale_Slider->setValue(100);
        scale_Slider->setOrientation(Qt::Horizontal);
        scale_Slider->setTickPosition(QSlider::NoTicks);
        vertexes_2 = new QLabel(centralwidget);
        vertexes_2->setObjectName(QString::fromUtf8("vertexes_2"));
        vertexes_2->setGeometry(QRect(921, 439, 101, 31));
        vertexes_2->setFont(font);
        vertexes_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(255, 255, 255);\n"
"  border: 1px solid rgb(0, 0, 0);\n"
"}"));
        color_back = new QPushButton(centralwidget);
        color_back->setObjectName(QString::fromUtf8("color_back"));
        color_back->setGeometry(QRect(905, 470, 121, 35));
        color_back->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color:rgb(157, 104, 255);\n"
"  color: rgb(255, 255, 255); \n"
"  border: 1px solid rgb(157, 104, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"       background-color: rgb(112, 70, 183);\n"
" border: 1px solid rgb(0, 0, 0);\n"
"}"));
        vertexes_5 = new QLabel(centralwidget);
        vertexes_5->setObjectName(QString::fromUtf8("vertexes_5"));
        vertexes_5->setGeometry(QRect(794, 439, 89, 31));
        vertexes_5->setFont(font);
        vertexes_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(255, 255, 255);\n"
"  border: 1px solid rgb(0, 0, 0);\n"
"}"));
        color_lines = new QPushButton(centralwidget);
        color_lines->setObjectName(QString::fromUtf8("color_lines"));
        color_lines->setGeometry(QRect(777, 470, 121, 35));
        color_lines->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"  background-color:rgb(157, 104, 255);\n"
"  color: rgb(255, 255, 255); \n"
"  border: 1px solid rgb(157, 104, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"       background-color: rgb(112, 70, 183);\n"
" border: 1px solid rgb(0, 0, 0);\n"
"}"));
        vertexes_6 = new QLabel(centralwidget);
        vertexes_6->setObjectName(QString::fromUtf8("vertexes_6"));
        vertexes_6->setGeometry(QRect(660, 439, 104, 31));
        vertexes_6->setFont(font);
        vertexes_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(255, 255, 255);\n"
"  border: 1px solid rgb(0, 0, 0);\n"
"}"));
        color_vertexes = new QPushButton(centralwidget);
        color_vertexes->setObjectName(QString::fromUtf8("color_vertexes"));
        color_vertexes->setGeometry(QRect(650, 470, 121, 35));
        color_vertexes->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"  background-color:rgb(157, 104, 255);\n"
"  color: rgb(255, 255, 255); \n"
"  border: 1px solid rgb(157, 104, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"       background-color: rgb(112, 70, 183);\n"
" border: 1px solid rgb(0, 0, 0);\n"
"}"));
        projection_view = new QLabel(centralwidget);
        projection_view->setObjectName(QString::fromUtf8("projection_view"));
        projection_view->setGeometry(QRect(350, 520, 111, 21));
        projection_view->setFont(font);
        projection_view->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(255, 255, 255);\n"
"  border: 1px solid rgb(0, 0, 0);\n"
"}"));
        lines_view = new QLabel(centralwidget);
        lines_view->setObjectName(QString::fromUtf8("lines_view"));
        lines_view->setGeometry(QRect(510, 520, 101, 21));
        lines_view->setFont(font);
        lines_view->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(255, 255, 255);\n"
"  border: 1px solid rgb(0, 0, 0);\n"
"}"));
        centre = new QRadioButton(centralwidget);
        buttonGroup = new QButtonGroup(MainWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(centre);
        centre->setObjectName(QString::fromUtf8("centre"));
        centre->setGeometry(QRect(356, 550, 99, 20));
        centre->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	color: rgb(255, 255, 255);\n"
"  border: 1px solid rgb(0, 0, 0);\n"
"}"));
        continuous = new QRadioButton(centralwidget);
        buttonGroup_2 = new QButtonGroup(MainWindow);
        buttonGroup_2->setObjectName(QString::fromUtf8("buttonGroup_2"));
        buttonGroup_2->addButton(continuous);
        continuous->setObjectName(QString::fromUtf8("continuous"));
        continuous->setGeometry(QRect(510, 550, 99, 20));
        continuous->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	color: rgb(255, 255, 255);\n"
"  border: 1px solid rgb(0, 0, 0);\n"
"}"));
        parallel = new QRadioButton(centralwidget);
        buttonGroup->addButton(parallel);
        parallel->setObjectName(QString::fromUtf8("parallel"));
        parallel->setGeometry(QRect(356, 577, 99, 20));
        parallel->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	color: rgb(255, 255, 255);\n"
"  border: 1px solid rgb(0, 0, 0);\n"
"}"));
        dotted_line = new QRadioButton(centralwidget);
        buttonGroup_2->addButton(dotted_line);
        dotted_line->setObjectName(QString::fromUtf8("dotted_line"));
        dotted_line->setGeometry(QRect(510, 577, 99, 20));
        dotted_line->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	color: rgb(255, 255, 255);\n"
"  border: 1px solid rgb(0, 0, 0);\n"
"}"));
        spinBox_linethickness = new QSpinBox(centralwidget);
        spinBox_linethickness->setObjectName(QString::fromUtf8("spinBox_linethickness"));
        spinBox_linethickness->setGeometry(QRect(786, 553, 121, 31));
        spinBox_linethickness->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"color: rgb(255, 255, 255);\n"
"}"));
        formvertexes = new QLabel(centralwidget);
        formvertexes->setObjectName(QString::fromUtf8("formvertexes"));
        formvertexes->setGeometry(QRect(645, 520, 101, 13));
        formvertexes->setFont(font);
        formvertexes->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(255, 255, 255);\n"
"  border: 1px solid rgb(0, 0, 0);\n"
"}"));
        line_thickness = new QLabel(centralwidget);
        line_thickness->setObjectName(QString::fromUtf8("line_thickness"));
        line_thickness->setGeometry(QRect(790, 520, 101, 21));
        line_thickness->setFont(font);
        line_thickness->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(255, 255, 255);\n"
"  border: 1px solid rgb(0, 0, 0);\n"
"}"));
        spinBox_size_vertexes = new QSpinBox(centralwidget);
        spinBox_size_vertexes->setObjectName(QString::fromUtf8("spinBox_size_vertexes"));
        spinBox_size_vertexes->setGeometry(QRect(910, 553, 121, 31));
        spinBox_size_vertexes->setStyleSheet(QString::fromUtf8("QSpinBox {\n"
"color: rgb(255, 255, 255);\n"
"}"));
        size_vertexes = new QLabel(centralwidget);
        size_vertexes->setObjectName(QString::fromUtf8("size_vertexes"));
        size_vertexes->setGeometry(QRect(920, 520, 101, 21));
        size_vertexes->setFont(font);
        size_vertexes->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	color: rgb(255, 255, 255);\n"
"  border: 1px solid rgb(0, 0, 0);\n"
"}"));
        apply_line = new QPushButton(centralwidget);
        apply_line->setObjectName(QString::fromUtf8("apply_line"));
        apply_line->setGeometry(QRect(788, 603, 104, 31));
        apply_line->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"  background-color:rgb(157, 104, 255);\n"
"  color: rgb(255, 255, 255); \n"
"  border: 1px solid rgb(157, 104, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"       background-color: rgb(112, 70, 183);\n"
" border: 1px solid rgb(0, 0, 0);\n"
"}"));
        apply_vertexes = new QPushButton(centralwidget);
        apply_vertexes->setObjectName(QString::fromUtf8("apply_vertexes"));
        apply_vertexes->setGeometry(QRect(912, 603, 104, 31));
        apply_vertexes->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"  background-color:rgb(157, 104, 255);\n"
"  color: rgb(255, 255, 255); \n"
"  border: 1px solid rgb(157, 104, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"       background-color: rgb(112, 70, 183);\n"
" border: 1px solid rgb(0, 0, 0);\n"
"}"));
        apply_projection = new QPushButton(centralwidget);
        apply_projection->setObjectName(QString::fromUtf8("apply_projection"));
        apply_projection->setGeometry(QRect(354, 603, 104, 31));
        apply_projection->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"  background-color:rgb(157, 104, 255);\n"
"  color: rgb(255, 255, 255); \n"
"  border: 1px solid rgb(157, 104, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"       background-color: rgb(112, 70, 183);\n"
" border: 1px solid rgb(0, 0, 0);\n"
"}"));
        apply_vid_line = new QPushButton(centralwidget);
        apply_vid_line->setObjectName(QString::fromUtf8("apply_vid_line"));
        apply_vid_line->setGeometry(QRect(510, 603, 104, 31));
        apply_vid_line->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"  background-color:rgb(157, 104, 255);\n"
"  color: rgb(255, 255, 255); \n"
"  border: 1px solid rgb(157, 104, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"       background-color: rgb(112, 70, 183);\n"
" border: 1px solid rgb(0, 0, 0);\n"
"}"));
        scale_2 = new QDoubleSpinBox(centralwidget);
        scale_2->setObjectName(QString::fromUtf8("scale_2"));
        scale_2->setGeometry(QRect(690, 345, 71, 31));
        scale_2->setStyleSheet(QString::fromUtf8("QDoubleSpinBox {\n"
"color: rgb(255, 255, 255);\n"
"}"));
        scale_2->setMaximum(2.000000000000000);
        rotate_z = new QDoubleSpinBox(centralwidget);
        rotate_z->setObjectName(QString::fromUtf8("rotate_z"));
        rotate_z->setGeometry(QRect(690, 248, 71, 31));
        rotate_z->setStyleSheet(QString::fromUtf8("QDoubleSpinBox {\n"
"color: rgb(255, 255, 255);\n"
"}"));
        rotate_z->setMinimum(-5.000000000000000);
        rotate_z->setMaximum(5.000000000000000);
        rotate_z->setSingleStep(0.010000000000000);
        rotate_x = new QDoubleSpinBox(centralwidget);
        rotate_x->setObjectName(QString::fromUtf8("rotate_x"));
        rotate_x->setGeometry(QRect(690, 168, 71, 31));
        rotate_x->setStyleSheet(QString::fromUtf8("QDoubleSpinBox {\n"
"color: rgb(255, 255, 255);\n"
"}"));
        rotate_x->setMinimum(-5.000000000000000);
        rotate_x->setMaximum(5.000000000000000);
        rotate_x->setSingleStep(0.010000000000000);
        rotate_y = new QDoubleSpinBox(centralwidget);
        rotate_y->setObjectName(QString::fromUtf8("rotate_y"));
        rotate_y->setGeometry(QRect(690, 208, 71, 31));
        rotate_y->setStyleSheet(QString::fromUtf8("QDoubleSpinBox {\n"
"color: rgb(255, 255, 255);\n"
"}"));
        rotate_y->setMinimum(-5.000000000000000);
        rotate_y->setMaximum(5.000000000000000);
        rotate_y->setSingleStep(0.010000000000000);
        move_z_2 = new QDoubleSpinBox(centralwidget);
        move_z_2->setObjectName(QString::fromUtf8("move_z_2"));
        move_z_2->setGeometry(QRect(690, 85, 71, 31));
        move_z_2->setStyleSheet(QString::fromUtf8("QDoubleSpinBox {\n"
"color: rgb(255, 255, 255);\n"
"}"));
        move_z_2->setMinimum(-5.000000000000000);
        move_z_2->setMaximum(5.000000000000000);
        move_z_2->setSingleStep(0.010000000000000);
        move_y_2 = new QDoubleSpinBox(centralwidget);
        move_y_2->setObjectName(QString::fromUtf8("move_y_2"));
        move_y_2->setGeometry(QRect(690, 45, 71, 31));
        move_y_2->setStyleSheet(QString::fromUtf8("QDoubleSpinBox {\n"
"color: rgb(255, 255, 255);\n"
"}"));
        move_y_2->setMinimum(-5.000000000000000);
        move_y_2->setMaximum(5.000000000000000);
        move_y_2->setSingleStep(0.010000000000000);
        move_x_2 = new QDoubleSpinBox(centralwidget);
        move_x_2->setObjectName(QString::fromUtf8("move_x_2"));
        move_x_2->setGeometry(QRect(690, 5, 71, 31));
        move_x_2->setStyleSheet(QString::fromUtf8("QDoubleSpinBox {\n"
"color: rgb(255, 255, 255);\n"
"}"));
        move_x_2->setMinimum(-5.000000000000000);
        move_x_2->setMaximum(5.000000000000000);
        move_x_2->setSingleStep(0.010000000000000);
        default_2 = new QPushButton(centralwidget);
        default_2->setObjectName(QString::fromUtf8("default_2"));
        default_2->setGeometry(QRect(10, 579, 151, 54));
        default_2->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"  background-color:rgb(157, 104, 255);\n"
"  color: rgb(255, 255, 255); \n"
"  border: 1px solid rgb(157, 104, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"       background-color: rgb(112, 70, 183);\n"
" border: 1px solid rgb(0, 0, 0);\n"
"}"));
        no_vertex = new QRadioButton(centralwidget);
        no_vertex->setObjectName(QString::fromUtf8("no_vertex"));
        no_vertex->setGeometry(QRect(645, 544, 99, 14));
        no_vertex->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	color: rgb(255, 255, 255);\n"
"  border: 1px solid rgb(0, 0, 0);\n"
"}"));
        round_vertex = new QRadioButton(centralwidget);
        round_vertex->setObjectName(QString::fromUtf8("round_vertex"));
        round_vertex->setGeometry(QRect(645, 564, 99, 14));
        round_vertex->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	color: rgb(255, 255, 255);\n"
"  border: 1px solid rgb(0, 0, 0);\n"
"}"));
        square_vertex = new QRadioButton(centralwidget);
        square_vertex->setObjectName(QString::fromUtf8("square_vertex"));
        square_vertex->setGeometry(QRect(645, 583, 99, 14));
        square_vertex->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"	color: rgb(255, 255, 255);\n"
"  border: 1px solid rgb(0, 0, 0);\n"
"}"));
        apply_vertex_type = new QPushButton(centralwidget);
        apply_vertex_type->setObjectName(QString::fromUtf8("apply_vertex_type"));
        apply_vertex_type->setGeometry(QRect(650, 603, 104, 31));
        apply_vertex_type->setStyleSheet(QString::fromUtf8("\n"
"QPushButton {\n"
"  background-color:rgb(157, 104, 255);\n"
"  color: rgb(255, 255, 255); \n"
"  border: 1px solid rgb(157, 104, 255);\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"       background-color: rgb(112, 70, 183);\n"
" border: 1px solid rgb(0, 0, 0);\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);
        openGLWidget->raise();
        filename->raise();
        facets->raise();
        openfile->raise();
        screenshot->raise();
        move->raise();
        move_x_Slider->raise();
        move_y_Slider->raise();
        move_z_Slider->raise();
        rotation_y_Slider->raise();
        rotation->raise();
        rotation_z_Slider->raise();
        rotation_x_Slider->raise();
        move_x->raise();
        move_y->raise();
        move_z->raise();
        rotation_x->raise();
        rotation_y->raise();
        rotation_z->raise();
        scale->raise();
        scale_Slider->raise();
        vertexes_2->raise();
        color_back->raise();
        vertexes_5->raise();
        color_lines->raise();
        vertexes_6->raise();
        color_vertexes->raise();
        projection_view->raise();
        lines_view->raise();
        centre->raise();
        continuous->raise();
        parallel->raise();
        dotted_line->raise();
        spinBox_linethickness->raise();
        vertexes->raise();
        formvertexes->raise();
        line_thickness->raise();
        GIF->raise();
        spinBox_size_vertexes->raise();
        size_vertexes->raise();
        apply_line->raise();
        apply_vertexes->raise();
        apply_projection->raise();
        apply_vid_line->raise();
        scale_2->raise();
        rotate_z->raise();
        rotate_x->raise();
        rotate_y->raise();
        move_z_2->raise();
        move_y_2->raise();
        move_x_2->raise();
        default_2->raise();
        no_vertex->raise();
        round_vertex->raise();
        square_vertex->raise();
        apply_vertex_type->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1033, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        filename->setText(QCoreApplication::translate("MainWindow", "          FileName", nullptr));
        vertexes->setText(QCoreApplication::translate("MainWindow", "Vertexes", nullptr));
        facets->setText(QCoreApplication::translate("MainWindow", "Facets", nullptr));
        openfile->setText(QCoreApplication::translate("MainWindow", "Open File", nullptr));
        GIF->setText(QCoreApplication::translate("MainWindow", "GIF", nullptr));
        screenshot->setText(QCoreApplication::translate("MainWindow", "Screenshoot", nullptr));
        move->setText(QCoreApplication::translate("MainWindow", "Move", nullptr));
        rotation->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        move_x->setText(QCoreApplication::translate("MainWindow", "  X", nullptr));
        move_y->setText(QCoreApplication::translate("MainWindow", "  Y", nullptr));
        move_z->setText(QCoreApplication::translate("MainWindow", "  Z", nullptr));
        rotation_x->setText(QCoreApplication::translate("MainWindow", "  X", nullptr));
        rotation_y->setText(QCoreApplication::translate("MainWindow", "  Y", nullptr));
        rotation_z->setText(QCoreApplication::translate("MainWindow", "  Z", nullptr));
        scale->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        vertexes_2->setText(QCoreApplication::translate("MainWindow", "Back color", nullptr));
        color_back->setText(QCoreApplication::translate("MainWindow", "Change color", nullptr));
        vertexes_5->setText(QCoreApplication::translate("MainWindow", "Line color", nullptr));
        color_lines->setText(QCoreApplication::translate("MainWindow", "Change color", nullptr));
        vertexes_6->setText(QCoreApplication::translate("MainWindow", "Vertexes color", nullptr));
        color_vertexes->setText(QCoreApplication::translate("MainWindow", "Change color", nullptr));
        projection_view->setText(QCoreApplication::translate("MainWindow", "Projection type", nullptr));
        lines_view->setText(QCoreApplication::translate("MainWindow", "Line type", nullptr));
        centre->setText(QCoreApplication::translate("MainWindow", "Central", nullptr));
        continuous->setText(QCoreApplication::translate("MainWindow", "Solid line", nullptr));
        parallel->setText(QCoreApplication::translate("MainWindow", "Parallel", nullptr));
        dotted_line->setText(QCoreApplication::translate("MainWindow", "Dotted line", nullptr));
        formvertexes->setText(QCoreApplication::translate("MainWindow", "Vertex form", nullptr));
        line_thickness->setText(QCoreApplication::translate("MainWindow", "Line width", nullptr));
        size_vertexes->setText(QCoreApplication::translate("MainWindow", "Vertex size", nullptr));
        apply_line->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        apply_vertexes->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        apply_projection->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        apply_vid_line->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        default_2->setText(QCoreApplication::translate("MainWindow", "Standard settings", nullptr));
        no_vertex->setText(QCoreApplication::translate("MainWindow", "None", nullptr));
        round_vertex->setText(QCoreApplication::translate("MainWindow", "Round", nullptr));
        square_vertex->setText(QCoreApplication::translate("MainWindow", "Square", nullptr));
        apply_vertex_type->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
