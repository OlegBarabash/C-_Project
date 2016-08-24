#include <QPainter>
#include <QMouseEvent>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include <QtDebug>
#include <QLineEdit>
#include <QInputDialog>
#include <QStack>
#include "canvas.h"


Canvas::Canvas()
{
    pic = new QPixmap(600, 400);
    pic->fill();
    setPixmap(*pic);
    started = false;
    figDraw = 'p';
    painter = new QPainter(pic);
    painter->setPen(pen);
    painter->begin(pic);
}

Canvas::~Canvas()
{
    painter->end();
    delete painter;
    delete pic;
}

void Canvas::toBack()
{
    if(back_container.isEmpty())
    {
        return;
    }else{
        painter->end();
        forw_container.push_back(*pic);
        *pic = back_container.takeLast();
        setPixmap(*pic);
        painter->begin(pic);
        painter->setPen(pen);
    }
}

void Canvas::toForw()
{
    if(forw_container.isEmpty())
    {
        return;
    }else{
        painter->end();
        back_container.push_back(*pic);
        *pic = forw_container.takeLast();
        setPixmap(*pic);
        painter->begin(pic);
        painter->setPen(pen);
    }
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    forw_container.clear();
    back_container.push_back(*pic);

    pres = event->pos();
    if( figDraw != 'e')
        painter->setPen(pen);
    if( figDraw == 'p' || figDraw == 'e')
    {
        painter->drawPoint(pres);
        started = true;
        setPixmap(*pic);
    }
}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    switch (figDraw) {
    case 'e':
    case 'p':
    {
        painter->drawLine(pres, event->pos());
        pres = event->pos();
        started = true;
        setPixmap(*pic);
    }
        break;
    case 'l':
    {
        QPixmap p;
        p = *pic;
        QPainter paint(&p);
        paint.setPen( painter->pen());
        paint.drawLine(pres, event->pos());
        setPixmap(p);
    }
        break;
    case 'r':
    {
        QPixmap p;
        p = *pic;
        QPainter paint(&p);
        paint.setPen( painter->pen());
        QRect rec(pres, event->pos());
        paint.drawRect(rec);
        setPixmap(p);
    }
        break;
    case 'c':
    {
        QPixmap p;
        p = *pic;
        QPainter paint(&p);
        paint.setPen( painter->pen());
        QRect rec(pres, event->pos());
        paint.drawEllipse(rec);
        setPixmap(p);
    }
        break;
    default:
        break;
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{

    relis = event->pos();

    switch (figDraw) {
    case 'l':
    {
        line_draw( pres, relis );
    }
        break;
    case 'r':
    {
        rect_draw( pres, relis );
    }
        break;
    case 'c':
    {
        ellips_draw( pres, relis );
    }
        break;
    case 'f':
    {
        fillPath(relis);
    }
        break;
    case 't':
    {
        draw_text(relis);
    }
        break;
    default:
        break;
    }
}

void Canvas::line_draw(QPoint a, QPoint b)
{
    painter->drawLine(a, b);
    setPixmap(*pic);
    started = true;
}

void Canvas::rect_draw(QPoint a, QPoint b)
{
    QRect rec(a, b);
    painter->drawRect(rec);
    setPixmap(*pic);
    started = true;
}

void Canvas::ellips_draw(QPoint a, QPoint b)
{
    QRect rec(a, b);
    painter->drawEllipse(rec);
    setPixmap(*pic);
    started = true;
}

void Canvas::savePic(QString s)
{
    pic->save(s);
    started = false;
}

void Canvas::openPic(QString s)
{
    pic->load(s);
    setPixmap(*pic);
    started = false;
}

void Canvas::draw_text(QPoint a)
{
    QString str = QInputDialog::getText(this, tr("Text"), tr("Write the text:") );
    painter->drawText(a,str);
    setPixmap(*pic);
    started = true;
}

void Canvas::fillPath(QPoint a)
{
    QImage im;
    im = pic->toImage();
    im = floodFillScanlineStack(im,a.x(),a.y(),pen.color().rgb(),im.pixel(a));

    delete painter;
    delete pic;

    pic = new QPixmap(QPixmap::fromImage(im, Qt::AutoColor));
    painter = new QPainter(pic);
    painter->setPen(pen);
    setPixmap(*pic);

    started = true;
}

QImage Canvas::floodFillScanlineStack(QImage & img, int x, int y, QRgb newColor, QRgb oldColor)
{
    if (oldColor == newColor)
        return img;

    QStack<QPoint> stk;
    QPoint pt;

    int y1;
    bool spanLeft, spanRight;

    stk.push(QPoint(x, y));

    while (!stk.empty())
    {
        pt = stk.pop();
        x = pt.x();
        y = pt.y();

        y1 = y;
        while (y1 >= 0 && img.pixel(x, y1) == oldColor) y1--;
        y1++;

        spanLeft = spanRight = false;
        while (y1 < img.height() && img.pixel(x, y1) == oldColor)
        {
            img.setPixel(x, y1, newColor);
            if (!spanLeft && x > 0 && img.pixel(x-1, y1) == oldColor)
            {
                stk.push(QPoint(x-1, y1));
                spanLeft = true;
            } else if(spanLeft && x > 0 && img.pixel(x-1, y1) != oldColor) {
                spanLeft = false;
            }
            if (!spanRight && x < (img.width() - 1) && img.pixel(x+1, y1) == oldColor)
            {
                stk.push(QPoint(x+1, y1));
                spanRight = true;
            } else if(spanRight && (x < img.width() - 1) && img.pixel(x+1, y1) != oldColor) {
                spanRight = false;
            }
            y1++;
        }
    }
    return img;
}
