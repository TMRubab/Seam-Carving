#include "object_removal_marker.h"

object_removal_marker::object_removal_marker(QWidget *parent)
    : QWidget(parent)
{
    setAttribute(Qt::WA_StaticContents);
}

bool object_removal_marker::openImage(const QString &fileName)
{
    QImage loadedImage;
    if (!loadedImage.load(fileName))
        return false;
    // first thingy!!!
    image = loadedImage;
    update();
    return true;
}


void object_removal_marker::clearImage()
{
    image.fill(qRgb(255, 255, 255));
    update();
}










