#include "super_label.h"

super_label::super_label(QWidget* parent) : QLabel(parent)
{
}


void super_label::setVal(int val) {
    double res = val / 99.0 + 0.5;
    res = round(res * 1000.0) / 1000.0;
    setNum(res);
}
