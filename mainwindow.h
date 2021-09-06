#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <opencv2/opencv.hpp>
#include "SeamCarver.cpp"
#include "dialog.h"
#include "drawingview.h"
#include <QList>

using namespace cv;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void delete_picture();

    void delete_marker();

    void create_marker();

    void cancel_drawing();

private slots:
    void on_actionImport_image_triggered();

    void on_actionClear_image_triggered();

    void on_actionResize_triggered();

    void on_actionExport_image_triggered();

    void on_actionObject_removal_triggered();

    void on_actionRemove_triggered();

    void on_actionCancel_triggered();

    void on_actionProject_triggered();

    void on_actionAuthors_triggered();

    void rescale_image();

    void receive_and_draw(QPoint p1, QPoint p2, QPen pen);

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    QGraphicsPixmapItem* picture{nullptr};
    SeamCarver<Vec3b, uint8_t>* seam_carver{nullptr};
    Dialog* dialog{nullptr};
    bool** chosen{nullptr};
    bool marker_disabled{ true };
    int width{ 0 }, height{ 0 };
    QList<QGraphicsItem*> marker_tracked;
};
#endif // MAINWINDOW_H
