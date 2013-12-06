#ifndef CIRCLEWIDGET_H
#define CIRCLEWIDGET_H

#include <QWidget>
#include <QtGui>
#include <QtCore>

//! [0]
class CircleWidget : public QWidget
{
    Q_OBJECT

public:
    CircleWidget(QWidget *parent = 0);

    enum ColorKind{RED,GREEN,BLUE};

    void setFloatBased(bool floatBased);
    void setAntialiased(bool antialiased);
    void setColorKind(ColorKind c);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

public slots:
    void nextAnimationFrame();

    void slot_timeout();
protected:
    void paintEvent(QPaintEvent *event);

private:
    bool floatBased;
    bool antialiased;
    int frameNo;

    QTimer timer;
    ColorKind currentKind;

};
//! [0]

#endif
