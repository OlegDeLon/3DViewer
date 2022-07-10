#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "widget.h"
#include "geometry.h"
#include <QFileDialog>
#include "qgifimage.h"
#include <QTimer>
#include <fstream>
#include <QDir>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_openfile_clicked();

    void on_screenshot_clicked();

    void on_color_back_clicked();

    void on_color_lines_clicked();

    void on_apply_line_clicked();

    void on_scale_clicked();

    void on_move_clicked();

    void on_rotation_clicked();

    void on_scale_Slider_valueChanged(int value);

    void on_move_x_Slider_valueChanged(int value);

    void on_move_y_Slider_valueChanged(int value);

    void on_move_z_Slider_valueChanged(int value);

    void on_rotation_x_Slider_valueChanged(int value);

    void on_rotation_y_Slider_valueChanged(int value);

    void on_rotation_z_Slider_valueChanged(int value);

    void on_GIF_clicked();

    void TimerSlot();

    void on_apply_projection_clicked();

//    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_apply_vid_line_clicked();

    void on_apply_vertexes_clicked();

    void on_color_vertexes_clicked();

    void on_default_2_clicked();

    void save_settings();

    void load_settings();

    void on_apply_vertex_type_clicked();

private:
    Ui::MainWindow *ui;
    QColor *LineColor = new QColor(255, 249, 0, 0);
    QColor *ColorBack = new QColor(182, 0, 255, 255);
    QColor *VerColor = new QColor();
    QGifImage *gif;
    QImage *photo;
    QTimer *timer;
    QString path;
    int red, green, blue, alpha;
    int time;
    std::string savepath;

    struct settings
    {
        int line_width;
        int vertex_size;
        QColor *colorline = new QColor();
        QColor *colorback = new QColor();
        QColor *colorver = new QColor();
        int rgb_line[4];
        int rgb_back[4];
        int rgb_ver[4];
        int vertsflag;
        int sphereflag;
        int dotflag;
        int projectiontype;
    };
};

#endif // MAINWINDOW_H
