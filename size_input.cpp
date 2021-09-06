#include "size_input.h"
#include "ui_size_input.h"
#include <QDebug>

size_input::size_input(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::size_input)
{
    ui->setupUi(this);
    setWindowTitle(tr("Enter scales"));
}

size_input::~size_input()
{
    delete ui;
}


void size_input::on_pushButton_clicked()
{

}

