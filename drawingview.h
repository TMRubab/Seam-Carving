#pragma once
#include<QGraphicsView>

class drawingview : public QGraphicsView
{
	Q_OBJECT

public:
	drawingview(QWidget* parent);

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    //void paintEvent(QPaintEvent *event) override;

private:
    void drawLineTo(const QPoint& endPoint);

    int penWidth{ 5 };
    QColor penColor = Qt::red;
    bool scribbling = false;
    QPoint lastPoint;

signals:
    void draw_image(QPoint p1, QPoint p2, QPen pen);
};

