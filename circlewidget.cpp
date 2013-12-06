#include <QtGui>

#include "circlewidget.h"

#include <stdlib.h>

//! [0]
CircleWidget::CircleWidget(QWidget *parent)
    : QWidget(parent)
{
    floatBased = false;
    antialiased = false;
    frameNo = 0;

    this->setAutoFillBackground(false);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);

    connect(&timer,SIGNAL(timeout()),this,SLOT(slot_timeout()));
    timer.start(100);

    currentKind = RED;
}
//! [0]

//! [1]
void CircleWidget::setFloatBased(bool floatBased)
{
    this->floatBased = floatBased;
    update();
}
//! [1]

//! [2]
void CircleWidget::setAntialiased(bool antialiased)
{
    this->antialiased = antialiased;
    update();
}
//! [2]

void CircleWidget::setColorKind(ColorKind c)
{
    currentKind = c;
}

//! [3]
QSize CircleWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}
//! [3]

//! [4]
QSize CircleWidget::sizeHint() const
{
    return QSize(180, 180);
}
//! [4]

//! [5]
void CircleWidget::nextAnimationFrame()
{
    ++frameNo;
    update();
}
//! [5]
void CircleWidget::slot_timeout()
{
    nextAnimationFrame();
}

//! [6]
void CircleWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, antialiased);
    painter.translate(width() / 2, height() / 2);
//! [6]

//! [7]
    for (int diameter = 0; diameter < 256; diameter += 9) {
        int delta = abs((frameNo % 128) - diameter / 2);
        int alpha = 255 - (delta * delta) / 4 - diameter;
//! [7] //! [8]
        if (alpha > 0) {

            if(currentKind == RED)
            {
                painter.setPen(QPen(QColor(255, diameter / 2, 0, alpha), 3));
            }
            else if(currentKind == GREEN)
            {
                painter.setPen(QPen(QColor(diameter / 2,255 , 0, alpha), 3));

            }
            else
            {
                painter.setPen(QPen(QColor(diameter / 2,0 , 255, alpha), 3));
            }



            if (floatBased) {
                painter.drawEllipse(QRectF(-diameter / 2.0, -diameter / 2.0,
                                           diameter, diameter));
            } else {
                painter.drawEllipse(QRect(-diameter / 2, -diameter / 2,
                                          diameter, diameter));
            }
        }
    }
}
//! [8]
