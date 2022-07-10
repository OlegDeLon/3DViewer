#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>

#ifdef __cplusplus
extern "C" {
#include "../parse.h"
}
#endif

data_d anotherdata;
data_d *anotherpdata = &anotherdata;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    savepath = std::filesystem::current_path();
    savepath += "/settings.bin";
    qDebug() << std::filesystem::current_path();
    std::ifstream file;
    file.open(savepath);
    if (file) {
        load_settings();
    }
}

MainWindow::~MainWindow()
{
    save_settings();
    delete ui;
}

void MainWindow::on_openfile_clicked()
{
    QString str = QFileDialog::getOpenFileName(this, "open file", "/", "*.obj");

    ui->rotation_x_Slider->setValue(0);
    ui->rotation_y_Slider->setValue(0);
    ui->rotation_z_Slider->setValue(0);
    ui->move_x_Slider->setValue(0);
    ui->move_y_Slider->setValue(0);
    ui->move_z_Slider->setValue(0);
    ui->scale_Slider->setValue(100);
        if (str.length()) {
            ui->openGLWidget->geometries->flag_for_to_draw = 1;
            QList<QString> name = str.split('/');
            QByteArray barr = str.toLatin1();
            QString alala = (char *) barr.data();

            anotherpdata->count_of_vertexes = 0;
            anotherpdata->count_of_facets_all = 0;

            QFile inputFile(alala);
            inputFile.open(QIODevice::ReadOnly);
            QTextStream stream(&inputFile);
            for (QString line = stream.readLine();!line.isNull();line = stream.readLine()) {
                QByteArray string = line.toLocal8Bit();
                 char* str = string.data();
                parse1(anotherpdata, str);
            }
            inputFile.close();

            int vertexez = anotherpdata->count_of_vertexes;
            int facetz = anotherpdata->count_of_facets_all;

            ui->openGLWidget->geometries->filepath = alala;

                   QString vertexes = QString::number(vertexez);
                   QString facets = QString::number(facetz);
                   ui->filename->setText(name.last());
                   ui->vertexes->setText("Vertexes: " + vertexes);
                   ui->facets->setText("Facets: " + facets);
                   ui->openGLWidget->geometries->parsing();
                   ui->openGLWidget->geometries->drawprocess(&ui->openGLWidget->program);
        }
}

void MainWindow::on_screenshot_clicked()
{
    QDate date;
    QTime time;
    QString curtime = time.currentTime().toString();
    QString curdate = date.currentDate().toString();
    QString filepath = QFileDialog::getExistingDirectory();
    ui->openGLWidget->grabFramebuffer().save(filepath + "/" + curdate + curtime + ".BMP", NULL, 100);
    ui->openGLWidget->grabFramebuffer().save(filepath + "/" + curdate + curtime + ".JPG", NULL, 100);
}

void MainWindow::on_color_back_clicked()
{
    *ColorBack = QColorDialog::getColor(*ui->openGLWidget->color_back);
    ui->openGLWidget->color_back = ColorBack;
    ui->openGLWidget->updating();
}

void MainWindow::on_color_lines_clicked()
{
    *LineColor = QColorDialog::getColor(*ui->openGLWidget->color);
    ui->openGLWidget->color = LineColor;
    ui->openGLWidget->updating();
}

void MainWindow::on_color_vertexes_clicked()
{
    *VerColor = QColorDialog::getColor(*ui->openGLWidget->color_ver);
    ui->openGLWidget->color_ver = VerColor;
    ui->openGLWidget->updating();
}

void MainWindow::on_apply_line_clicked()
{
    ui->openGLWidget->line_width = ui->spinBox_linethickness->value();
    ui->openGLWidget->updating();
}

void MainWindow::on_apply_vertexes_clicked()
{
    ui->openGLWidget->vertex_size = ui->spinBox_size_vertexes->value();
     ui->openGLWidget->updating();
}

void MainWindow::on_scale_clicked()
{
    double value = (double)ui->scale_2->value();
    ui->openGLWidget->geometries->scaling(value);
    ui->openGLWidget->updating();
}

void MainWindow::on_move_clicked()
{
    double value_x = (double)ui->move_x_2->value();
    double value_y = (double)ui->move_y_2->value();
    double value_z = (double)ui->move_z_2->value();
    ui->openGLWidget->geometries->moving_x(value_x);
    ui->openGLWidget->geometries->moving_y(value_y);
    ui->openGLWidget->geometries->moving_z(value_z);
    ui->openGLWidget->updating();
}

void MainWindow::on_rotation_clicked()
{
    double value_x = (double)ui->rotate_x->value();
    double value_y = (double)ui->rotate_y->value();
    double value_z = (double)ui->rotate_z->value();
    ui->openGLWidget->geometries->rotating_x(value_x);
    ui->openGLWidget->geometries->rotating_x(value_y);
    ui->openGLWidget->geometries->rotating_x(value_z);
    ui->openGLWidget->updating();
}

void MainWindow::on_scale_Slider_valueChanged(int value)
{
    float new_value = (float)value / 100;
    ui->scale_2->setValue(new_value);
    ui->openGLWidget->geometries->scaling(new_value);
    ui->openGLWidget->updating();
}

void MainWindow::on_move_x_Slider_valueChanged(int value)
{
    float new_value = (float)value / 100;
    ui->move_x_2->setValue(new_value);
    ui->openGLWidget->geometries->moving_x(new_value);
    ui->openGLWidget->updating();
}

void MainWindow::on_move_y_Slider_valueChanged(int value)
{
    float new_value = (float)value / 100;
    ui->move_y_2->setValue(new_value);
    ui->openGLWidget->geometries->moving_y(new_value);
    ui->openGLWidget->updating();
}
void MainWindow::on_move_z_Slider_valueChanged(int value)
{
    float new_value = (float)value / 100;
    ui->move_z_2->setValue(new_value);
    ui->openGLWidget->geometries->moving_z(new_value);
    ui->openGLWidget->updating();
}

void MainWindow::on_rotation_x_Slider_valueChanged(int value)
{
    float new_value = (float)value / 100;
    ui->rotate_x->setValue(new_value);
    ui->openGLWidget->geometries->rotating_x(new_value);
    ui->openGLWidget->updating();
}

void MainWindow::on_rotation_y_Slider_valueChanged(int value)
{
    float new_value = (float)value / 100;
    ui->rotate_y->setValue(new_value);
    ui->openGLWidget->geometries->rotating_y(new_value);
    ui->openGLWidget->updating();
}

void MainWindow::on_rotation_z_Slider_valueChanged(int value)
{
    float new_value = (float)value / 100;
    ui->rotate_z->setValue(new_value);
    ui->openGLWidget->geometries->rotating_z(new_value);
    ui->openGLWidget->updating();
}


void MainWindow::on_GIF_clicked()
{
    path = QFileDialog::getExistingDirectory();
    gif = new QGifImage;
    photo = new QImage;
    time = 0;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(TimerSlot()));
    timer->start(100);
}

void MainWindow::TimerSlot()
{
    QDate date;
    QTime currtime;
    QString curtime = currtime.currentTime().toString();
    QString curdate = date.currentDate().toString();
    time++;
    *photo = ui->openGLWidget->grabFramebuffer();
    gif->addFrame(*photo);
    if (time == 50) {
        timer->stop();
        gif->save(path + "/" + curdate + " " + curtime + ".GIF");
    }
}

void MainWindow::on_apply_projection_clicked()
{
    if (ui->parallel->isChecked()) {
        ui->openGLWidget->projection_ortho = 1;
    } else {
        ui->openGLWidget->projection_ortho = 0;
    }
    ui->openGLWidget->resizeGL(640, 480);
    ui->openGLWidget->updating();
}


//void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
//{
//    if(arg1 == "No") {
//         ui->openGLWidget->geometries->flag_ver = 0;
//        ui->openGLWidget->geometries->flag_sphere = 0;
//    } else if (arg1 == "Round") {
//        ui->openGLWidget->geometries->flag_ver = 1;
//        ui->openGLWidget->geometries->flag_sphere = 1;
//    } else if (arg1 == "Square") {
//        ui->openGLWidget->geometries->flag_ver = 1;
//        ui->openGLWidget->geometries->flag_sphere = 0;
//    }
//    ui->openGLWidget->updating();
//}

void MainWindow::on_apply_vertex_type_clicked()
{
    if (ui->no_vertex->isChecked()) {
        ui->openGLWidget->flag_ver = 0;
        ui->openGLWidget->flag_sphere = 0;
        ui->openGLWidget->updating();
    } else if (ui->round_vertex->isChecked()) {
        ui->openGLWidget->flag_ver = 1;
        ui->openGLWidget->flag_sphere = 1;
        ui->openGLWidget->updating();
    } else if (ui->square_vertex->isChecked()) {
        ui->openGLWidget->flag_ver = 1;
        ui->openGLWidget->flag_sphere = 0;
        ui->openGLWidget->updating();
    }
//    ui->openGLWidget->updating();
}

void MainWindow::on_apply_vid_line_clicked()
{
    if(ui->dotted_line->isChecked()) {
     ui->openGLWidget->flag_dotted = 1;
      ui->openGLWidget->updating();
    } else {
        ui->openGLWidget->flag_dotted = 0;
         ui->openGLWidget->updating();
    }
}


void MainWindow::on_default_2_clicked()
{
    ui->rotation_x_Slider->setValue(0);
    ui->rotation_y_Slider->setValue(0);
    ui->rotation_z_Slider->setValue(0);
    ui->move_x_Slider->setValue(0);
    ui->move_y_Slider->setValue(0);
    ui->move_z_Slider->setValue(0);
    ui->scale_Slider->setValue(100);
    ui->spinBox_linethickness->setValue(1);
    ui->spinBox_size_vertexes->setValue(2);
    ui->openGLWidget->line_width = ui->spinBox_linethickness->value();
    ui->openGLWidget->color_back = ColorBack;
    ui->openGLWidget->color = LineColor;
    ui->openGLWidget->flag_dotted = 0;
    ui->openGLWidget->projection_ortho = 0;
     ui->openGLWidget->resizeGL(640, 480);
     ui->openGLWidget->flag_ver = 0;
     ui->openGLWidget->flag_sphere = 0;
    ui->openGLWidget->updating();
}


void MainWindow::save_settings()
{
    settings settings1;

    settings1.line_width = ui->spinBox_linethickness->value();
    settings1.vertex_size = ui->spinBox_size_vertexes->value();

    settings1.vertsflag = ui->openGLWidget->flag_ver;
    settings1.sphereflag = ui->openGLWidget->flag_sphere;

    ui->openGLWidget->color_back->getRgb(&red, &green, &blue, &alpha);
    settings1.rgb_back[0] = red;
    settings1.rgb_back[1] = green;
    settings1.rgb_back[2] = blue;
    settings1.rgb_back[3] = alpha;

    ui->openGLWidget->color->getRgb(&red, &green, &blue, &alpha);
    settings1.rgb_line[0] = red;
    settings1.rgb_line[1] = green;
    settings1.rgb_line[2] = blue;
    settings1.rgb_line[3] = alpha;

    ui->openGLWidget->color_ver->getRgb(&red, &green, &blue, &alpha);
    settings1.rgb_ver[0] = red;
    settings1.rgb_ver[1] = green;
    settings1.rgb_ver[2] = blue;
    settings1.rgb_ver[3] = alpha;

    settings1.dotflag = ui->dotted_line->isChecked();
    settings1.projectiontype = ui->parallel->isChecked() ? 1 : 0;

    std::ofstream output_file(savepath, std::ios::binary);
    output_file.write((char*)&settings1, sizeof(settings));
    output_file.close();

}


void MainWindow::load_settings()
{
    std::ifstream input_file(savepath, std::ios::binary);
    settings settings2;
    input_file.read((char*)&settings2, sizeof(settings2));

    if(settings2.vertsflag == 1 && settings2.sphereflag == 0) {
        ui->openGLWidget->flag_ver = 1;
        ui->openGLWidget->flag_sphere = 0;
        ui->openGLWidget->updating();
    } else if(settings2.vertsflag == 1 && settings2.sphereflag == 1) {
        ui->openGLWidget->flag_ver = 1;
        ui->openGLWidget->flag_sphere = 1;
        ui->openGLWidget->updating();
    } else if (settings2.sphereflag == 0 && settings2.vertsflag == 0) {
        ui->openGLWidget->flag_ver = 0;
        ui->openGLWidget->flag_sphere = 0;
        ui->openGLWidget->updating();
    }

    ui->openGLWidget->line_width = settings2.line_width;

    ui->spinBox_linethickness->setValue(settings2.line_width);

    ui->openGLWidget->vertex_size = settings2.vertex_size;

    ui->spinBox_size_vertexes->setValue(settings2.vertex_size);

    ui->openGLWidget->color_back->setRgb(settings2.rgb_back[0], settings2.rgb_back[1], settings2.rgb_back[2], settings2.rgb_back[3]);

    ui->openGLWidget->color->setRgb(settings2.rgb_line[0], settings2.rgb_line[1], settings2.rgb_line[2], settings2.rgb_line[3]);

    ui->openGLWidget->color_ver->setRgb(settings2.rgb_ver[0], settings2.rgb_ver[1], settings2.rgb_ver[2], settings2.rgb_ver[3]);


    if (settings2.dotflag == 1) {
        ui->openGLWidget->flag_dotted = 1;
        ui->openGLWidget->updating();
    }   else {
        ui->openGLWidget->flag_dotted = 0;
        ui->openGLWidget->updating();
    }

    if (settings2.projectiontype == 1) {
        ui->openGLWidget->projection_ortho = 1;
        ui->openGLWidget->resizeGL(640, 480);
        ui->openGLWidget->updating();
    } else {
        ui->openGLWidget->projection_ortho = 0;
        ui->openGLWidget->resizeGL(640, 480);
        ui->openGLWidget->updating();
    }
    ui->openGLWidget->updating();
}


