#ifndef CANVAS_H
#define CANVAS_H

#include <QPen>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QSize>
#include <QList>


class Canvas : public QLabel
{
public:
    Canvas();
    ~Canvas();

    friend class MainWindow;

    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void savePic(QString s);
    void openPic(QString s);
    void line_draw(QPoint a, QPoint b);
    void rect_draw(QPoint a, QPoint b);
    void ellips_draw(QPoint a, QPoint b);
    void fillPath(QPoint a);
    void draw_text(QPoint a);
    QImage floodFillScanlineStack(QImage & img, int x, int y, QRgb newColor, QRgb oldColor);
    void toBack();
    void toForw();

private:
    QPixmap* pic;
    QPainter *painter;
    QPoint pres;
    QPoint relis;
    bool started;
    char figDraw;
    QSize size_pic;
    QPen pen;
    QList<QPixmap> back_container;
    QList<QPixmap> forw_container;

};

#endif // CANVAS_H
