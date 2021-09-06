#include "drawingview.h"
#include <QMouseEvent>

drawingview::drawingview(QWidget* parent) : QGraphicsView(parent) {}

void drawingview::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        lastPoint = event->pos();
        scribbling = true;
    }
}


void drawingview::mouseMoveEvent(QMouseEvent* event)
{
    if ((event->buttons() & Qt::LeftButton) && scribbling)
        drawLineTo(event->pos());
}

void drawingview::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton && scribbling) {
        drawLineTo(event->pos());
        scribbling = false;
    }
}

void drawingview::drawLineTo(const QPoint& endPoint)
{
    QPoint p1 = lastPoint, p2 = endPoint; QPen pen(penColor);
    emit draw_image(p1, p2, pen);
    lastPoint = endPoint;
}


