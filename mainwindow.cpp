#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "SeamCarver.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("Seam carving"));

    ui->graphicsView->setScene(&scene);
    ui->graphicsView->show();

    connect(ui->graphicsView, &drawingview::draw_image, this, &MainWindow::receive_and_draw);

    ui->actionRemove->setVisible(false);
    ui->actionCancel->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionImport_image_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Import image", QDir::currentPath(), "Images (*.png *.jpg *.bmp)");
    if (filename == "") return;

    delete_picture();
    String filepath = filename.toStdString();

    Mat image = imread(filepath, IMREAD_COLOR);
    height = image.rows;
    width = image.cols;
    ui->graphicsView->setFixedSize(width + 10, height+10);

    picture = scene.addPixmap(QPixmap(filename));

    qDebug() << height << width;
    qDebug() << ui->graphicsView->height() << ui->graphicsView->width();
    seam_carver = new SeamCarver<Vec3b, uint8_t>(filepath, IMREAD_COLOR);
    create_marker();
}

void MainWindow::create_marker() {
    chosen = new bool* [height];
    for (int i = 0; i < height; ++i) {
        chosen[i] = new bool[width];
        memset(chosen[i], width, false);
    }
}


void MainWindow::delete_marker() {
    if (chosen == nullptr) return;
    for (int i = 0; i < height; ++i) {
        delete[] chosen[i];
    }
    delete[] chosen;
    chosen = nullptr;
    for (int i = 0; i < marker_tracked.size(); ++i) {
        delete marker_tracked[i];
    }
    marker_tracked.clear();
}

void MainWindow::receive_and_draw(QPoint p1, QPoint p2, QPen pen) {
    if (p1.x() >= ui->graphicsView->width() - 10 || p1.y() >= ui->graphicsView->height() - 10
        || p2.x() >= (ui->graphicsView->width() - 10) || p2.y() >= (ui->graphicsView->height() - 10)
        || p1.x() <= 20 || p1.y() <= 20 || p2.x() <= 20 || p2.y() <= 20
        || marker_disabled) return;
    marker_tracked.push_back(scene.addLine(QLine(p1, p2), pen));
    qDebug() << p1.x() << p1.y();
    chosen[p1.y()][p1.x()] = true;
    chosen[p2.y()][p2.x()] = true;
}



void MainWindow::on_actionClear_image_triggered()
{
    delete_marker();
    delete_picture();
    scene.clear();
}

void MainWindow::delete_picture() {
    if (picture == nullptr) return;
    delete picture;
    picture = nullptr;
    delete seam_carver;
}

void MainWindow::on_actionResize_triggered() 
{
    if (picture == nullptr) return;
    dialog = new Dialog();
    dialog->setModal(true);
    dialog->show();
    connect(dialog, &Dialog::signal_to_resize, this, &MainWindow::rescale_image);
}

void MainWindow::rescale_image() {
    seam_carver->rescale(dialog->get_width(), dialog->get_height());
    imshow("scaled", seam_carver->get_pic());
}

void MainWindow::on_actionExport_image_triggered()
{
    if (picture == nullptr) return;
    QString filename = QFileDialog::getSaveFileName(this, "Export image", QDir::currentPath(), "Images (*png *.jpg *bmp)");
    if (filename == "") return;
    imwrite(filename.toStdString(), seam_carver->get_pic());
}

void MainWindow::on_actionObject_removal_triggered()
{
    create_marker();

    if (picture == nullptr) return;
    ui->actionRemove->setVisible(true);
    ui->actionCancel->setVisible(true);

    ui->actionExport_image->setDisabled(true);
    ui->actionImport_image->setDisabled(true);
    ui->actionClear_image->setDisabled(true);
    ui->actionResize->setDisabled(true);

    // turn on the marker
    marker_disabled = false;
}

void MainWindow::cancel_drawing() {
    ui->actionRemove->setVisible(false);
    ui->actionCancel->setVisible(false);

    ui->actionExport_image->setDisabled(false);
    ui->actionImport_image->setDisabled(false);
    ui->actionClear_image->setDisabled(false);
    ui->actionResize->setDisabled(false);

    // turn of the marker
    marker_disabled = true;

    // delete marked stuff
    delete_marker();
}

void MainWindow::on_actionRemove_triggered() {
    QMessageBox::information(this, tr("admqwojdwm"), tr("dquiwdijqwjdi"));
    // remove objectooo and qwdokmqwdm
    seam_carver->remove_object(chosen);
    imshow("removed", seam_carver->get_pic());
    ui->actionRemove->setVisible(false);
    cancel_drawing();
}

void MainWindow::on_actionCancel_triggered() {
    cancel_drawing();
}

void MainWindow::on_actionProject_triggered()
{
    QMessageBox::information(this, tr("About the project"), 
        tr("This project implements <br> seam carving algorithm <br> for content-aware resizing"));
}

void MainWindow::on_actionAuthors_triggered()
{
    QMessageBox::information(this, tr("Authors"),
        tr("This project was done by <br> Alibek, Thanic, Rubab"));
}

    
