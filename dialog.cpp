#include "dialog.h"
#include "ui_dialog.h"
#include <QString>
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    


    // connecting sliders with scales that are displayed on the right
    connect(ui->SliderHeight, &QSlider::valueChanged, ui->label_height, &super_label::setVal);
    connect(ui->SliderWidth, &QSlider::valueChanged, ui->label_width, &super_label::setVal);
    

    connect(ui->SliderHeight, &QSlider::valueChanged, this, &Dialog::setHeightScale);
    connect(ui->SliderWidth, &QSlider::valueChanged, this, &Dialog::setWidthScale);

    ui->SliderHeight->setValue(49.5);
    ui->SliderWidth->setValue(49.5);

    //connect(ui->label_height, &super_label::updateScale, this, &Dialog::setHeightScale);
    //connect(ui->label_width, &super_label::updateScale, this, &Dialog::setWidthScale);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setWidthScale(int w)
{
    width_scale = w / 99.0 + 0.5;
    width_scale = round(width_scale * 1000.0) / 1000.0; // rounding up to 3 decimal points
}

void Dialog::setHeightScale(int h)
{
    height_scale = h / 99.0 + 0.5;
    height_scale = round(height_scale * 1000.0) / 1000.0; // same thing
}

void Dialog::on_pushButton_clicked()
{
    // proceessing and resizing image
    qDebug() << width_scale << height_scale;
    this->close();
    emit signal_to_resize();
}
