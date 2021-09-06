#ifndef SIZE_INPUT_H
#define SIZE_INPUT_H

#include <QDialog>

namespace Ui {
class size_input;
}

class size_input : public QDialog
{
    Q_OBJECT

public:
    explicit size_input(QWidget *parent = nullptr);
    ~size_input();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_pushButton_clicked();

    void on_lineEdit_height_textEdited(const QString &arg1);

private:
    Ui::size_input *ui;
    double width_scale{0};
    double height_scale{0};
};

#endif // SIZE_INPUT_H
