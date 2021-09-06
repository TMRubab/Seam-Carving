#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "super_label.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    double get_width() { return width_scale; }
    double get_height() { return height_scale; }

private slots:
    void on_pushButton_clicked();
    void setWidthScale(int w);
    void setHeightScale(int h);

private:
    Ui::Dialog *ui;
    double width_scale{ 0 };
    double height_scale{ 0 };

signals:
    void signal_to_resize();
};

#endif // DIALOG_H
