#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QtGui>
#include <QtCore>
#include <QGraphicsView>
#include <QtWidgets>

#include "wigglywidget.h"
#include "circlewidget.h"

class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit GraphicsView(QWidget *parent = 0);

signals:

public slots:
    void slot_scene1();
    void slot_scene2();
    void slot_scene3();
    void slot_scene4();

private:
    QGraphicsScene scene;

    QPropertyAnimation *m_animation;

    QGraphicsProxyWidget * graphicsProxyWidgetWigglyWidget1;
    QGraphicsProxyWidget * graphicsProxyWidgetWigglyWidget2;
    QGraphicsProxyWidget * graphicsProxyWidgetWigglyWidget3;

    QGraphicsPixmapItem *bg1;
    QGraphicsPixmapItem *bg2;
    QGraphicsPixmapItem *bg3;
    QGraphicsPixmapItem *bg4;

    QGraphicsPixmapItem *flower;

    QGraphicsOpacityEffect * graphicsOpacityEffect1;
    QGraphicsOpacityEffect * graphicsOpacityEffect2;
    QGraphicsOpacityEffect * graphicsOpacityEffect3;
    QGraphicsOpacityEffect * graphicsOpacityEffect4;

    QGraphicsTextItem * graphicsTextItem;

};

#endif
