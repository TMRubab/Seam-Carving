#ifndef OBJECT_REMOVAL_MARKER_H
#define OBJECT_REMOVAL_MARKER_H

#include<QWidget>


class object_removal_marker: public QWidget
{
    Q_OBJECT

public:
    object_removal_marker(QWidget *parent = nullptr);

    bool openImage(const QString &fileName);

public slots:
    void clearImage();

private:
    QImage image;

};
#endif // OBJECT_REMOVAL_MARKER_H
