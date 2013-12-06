#include "graphicsview.h"

GraphicsView::GraphicsView(QWidget *parent) :
    QGraphicsView(parent)
{

    setWindowTitle("Pirate!");
    setWindowIcon(QIcon(":/images/caomei.png"));

    QImage img(":/images/bg1.jpg");

    WigglyWidget * wigglyWidget = new WigglyWidget(40);
    wigglyWidget->setText("My Ship Black Pearl!");
    graphicsProxyWidgetWigglyWidget1 = scene.addWidget(wigglyWidget);
    graphicsProxyWidgetWigglyWidget1->setPos(0,300);

    wigglyWidget = new WigglyWidget(12);
    wigglyWidget->setText("I am looking for this.");
    graphicsProxyWidgetWigglyWidget2 = scene.addWidget(wigglyWidget);
    graphicsProxyWidgetWigglyWidget2->setPos(-300,-300);

    wigglyWidget = new WigglyWidget(20);
    wigglyWidget->setText("let's rock");
    graphicsProxyWidgetWigglyWidget3 = scene.addWidget(wigglyWidget);
    graphicsProxyWidgetWigglyWidget3->setPos(-300,-300);

    {

        CircleWidget *circleWidget = new CircleWidget;
        circleWidget->setAntialiased(true);
        circleWidget->setFloatBased(true);
        circleWidget->setColorKind(CircleWidget::RED);
        QGraphicsProxyWidget * graphicsProxyWidgetCircleWidget = scene.addWidget(circleWidget);
        graphicsProxyWidgetCircleWidget->setPos(0,0);

    }
    {

        CircleWidget *circleWidget = new CircleWidget;
        circleWidget->setAntialiased(true);
        circleWidget->setFloatBased(true);
        circleWidget->setColorKind(CircleWidget::GREEN);
        QGraphicsProxyWidget * graphicsProxyWidgetCircleWidget = scene.addWidget(circleWidget);
        graphicsProxyWidgetCircleWidget->setPos(400,150);

    }
    {

        CircleWidget *circleWidget = new CircleWidget;
        circleWidget->setAntialiased(true);
        circleWidget->setFloatBased(true);
        circleWidget->setColorKind(CircleWidget::BLUE);
        QGraphicsProxyWidget * graphicsProxyWidgetCircleWidget = scene.addWidget(circleWidget);
        graphicsProxyWidgetCircleWidget->setPos(500,250);

    }


    QGraphicsItem *lightSource;
    QRadialGradient radialGrad(30, 30, 30);
    radialGrad.setColorAt(0, Qt::yellow);
    radialGrad.setColorAt(0.2, Qt::yellow);
    radialGrad.setColorAt(1, Qt::transparent);
    QPixmap pixmap(60, 60);
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    painter.setPen(Qt::NoPen);
    painter.setBrush(radialGrad);
    painter.drawEllipse(0, 0, 60, 60);
    painter.end();
    lightSource = scene.addPixmap(pixmap);
    lightSource->setZValue(2);

    scene.setSceneRect(0, 0, img.width(), img.height());


    graphicsOpacityEffect1 = new QGraphicsOpacityEffect;
    graphicsOpacityEffect1->setOpacity(1);

    graphicsOpacityEffect2 = new QGraphicsOpacityEffect;
    graphicsOpacityEffect2->setOpacity(0);

    graphicsOpacityEffect3 = new QGraphicsOpacityEffect;
    graphicsOpacityEffect3->setOpacity(0);

    graphicsOpacityEffect4 = new QGraphicsOpacityEffect;
    graphicsOpacityEffect4->setOpacity(0);

    bg1 = scene.addPixmap(QPixmap(":/images/bg1.jpg"));
    bg1->setZValue(-1);
    bg1->setGraphicsEffect(graphicsOpacityEffect1);
    bg1->setVisible(true);

    bg2 = scene.addPixmap(QPixmap(":/images/bg2.jpg"));
    bg2->setZValue(-1);
    bg2->setGraphicsEffect(graphicsOpacityEffect2);
    bg2->setVisible(true);

    bg3 = scene.addPixmap(QPixmap(":/images/bg3.jpg"));
    bg3->setZValue(-1);
    bg3->setGraphicsEffect(graphicsOpacityEffect3);
    bg3->setVisible(true);

    QPixmap pixmapTemp(600,600);
    pixmapTemp.fill(Qt::green);
    bg4 = scene.addPixmap(pixmapTemp);
    bg4->setZValue(-1);
    bg4->setGraphicsEffect(graphicsOpacityEffect4);
    bg4->setVisible(true);


    flower = scene.addPixmap(QPixmap(":/images/flower.png"));
    flower->setOffset(50,50);

    flower->setVisible(false);

    QGraphicsColorizeEffect * graphicsColorizeEffect = new QGraphicsColorizeEffect;
    graphicsColorizeEffect->setColor(QColor(255,125,125));
    graphicsColorizeEffect->setStrength(1);




    graphicsTextItem = scene.addText("Here i am,\n let's go\nim going to find treasure on this island");
    graphicsTextItem->setPos(100,-300);
    graphicsTextItem->setFont(QFont("свт╡", 12, QFont::Bold));

    setAlignment(Qt::AlignCenter);
    setCacheMode(QGraphicsView::CacheBackground);
    setRenderHint(QPainter::Antialiasing);
    setScene(&scene);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedWidth(img.width());
    setFixedHeight(img.height());


    m_animation = new QPropertyAnimation(graphicsProxyWidgetWigglyWidget1, "y", this);
    m_animation->setDuration(5000);
    m_animation->setEasingCurve(QEasingCurve::Linear);
    m_animation->setStartValue(-300);
    m_animation->setEndValue(280);
    m_animation->setDirection(QAbstractAnimation::Forward);
    m_animation->start();

    QTimer::singleShot(20000,this,SLOT(slot_scene1()));
}

void GraphicsView::slot_scene1()
{

    m_animation = new QPropertyAnimation(graphicsProxyWidgetWigglyWidget1, "x", this);
    m_animation->setDuration(5000);
    m_animation->setEasingCurve(QEasingCurve::Linear);
    m_animation->setEndValue(-700);
    m_animation->setDirection(QAbstractAnimation::Forward);
    m_animation->start();


    m_animation = new QPropertyAnimation(graphicsTextItem, "y", this);
    m_animation->setDuration(5000);
    m_animation->setEasingCurve(QEasingCurve::Linear);

    m_animation->setEndValue(450);
    m_animation->setDirection(QAbstractAnimation::Forward);
    m_animation->start();

    m_animation = new QPropertyAnimation(graphicsOpacityEffect1, "opacity", this);
    m_animation->setDuration(5000);
    m_animation->setEasingCurve(QEasingCurve::Linear);

    m_animation->setEndValue(0);
    m_animation->setDirection(QAbstractAnimation::Forward);
    m_animation->start();

    m_animation = new QPropertyAnimation(graphicsOpacityEffect2, "opacity", this);
    m_animation->setDuration(5000);
    m_animation->setEasingCurve(QEasingCurve::Linear);
    m_animation->setEndValue(1);
    m_animation->setDirection(QAbstractAnimation::Forward);
    m_animation->start();

    QTimer::singleShot(20000,this,SLOT(slot_scene2()));

}

void GraphicsView::slot_scene2()
{

    m_animation = new QPropertyAnimation(graphicsTextItem, "y", this);
    m_animation->setDuration(5000);
    m_animation->setEasingCurve(QEasingCurve::Linear);
    m_animation->setEndValue(1000);
    m_animation->setDirection(QAbstractAnimation::Forward);
    m_animation->start();



    graphicsProxyWidgetWigglyWidget2->setPos(600,300);
    m_animation = new QPropertyAnimation(graphicsProxyWidgetWigglyWidget2, "x", this);
    m_animation->setDuration(5000);
    m_animation->setEasingCurve(QEasingCurve::Linear);
    m_animation->setEndValue(0);
    m_animation->setDirection(QAbstractAnimation::Forward);
    m_animation->start();


    m_animation = new QPropertyAnimation(graphicsOpacityEffect2, "opacity", this);
    m_animation->setDuration(5000);
    m_animation->setEasingCurve(QEasingCurve::Linear);
    m_animation->setEndValue(0);
    m_animation->setDirection(QAbstractAnimation::Forward);
    m_animation->start();

    m_animation = new QPropertyAnimation(graphicsOpacityEffect3, "opacity", this);
    m_animation->setDuration(5000);
    m_animation->setEasingCurve(QEasingCurve::Linear);
    m_animation->setEndValue(1);
    m_animation->setDirection(QAbstractAnimation::Forward);
    m_animation->start();


    QTimer::singleShot(20000,this,SLOT(slot_scene3()));

}

void GraphicsView::slot_scene3()
{

    m_animation = new QPropertyAnimation(graphicsProxyWidgetWigglyWidget2, "x", this);
    m_animation->setDuration(3000);
    m_animation->setEasingCurve(QEasingCurve::Linear);

    m_animation->setEndValue(-600);
    m_animation->setDirection(QAbstractAnimation::Forward);
    m_animation->start();

    graphicsProxyWidgetWigglyWidget3->setPos(600,300);
    m_animation = new QPropertyAnimation(graphicsProxyWidgetWigglyWidget3, "x", this);
    m_animation->setDuration(5000);
    m_animation->setEasingCurve(QEasingCurve::Linear);

    m_animation->setEndValue(0);
    m_animation->setDirection(QAbstractAnimation::Forward);
    m_animation->start();


    m_animation = new QPropertyAnimation(graphicsOpacityEffect3, "opacity", this);
    m_animation->setDuration(5000);
    m_animation->setEasingCurve(QEasingCurve::Linear);
    m_animation->setEndValue(0);
    m_animation->setDirection(QAbstractAnimation::Forward);
    m_animation->start();

    m_animation = new QPropertyAnimation(graphicsOpacityEffect4, "opacity", this);
    m_animation->setDuration(5000);
    m_animation->setEasingCurve(QEasingCurve::Linear);
    m_animation->setEndValue(1);
    m_animation->setDirection(QAbstractAnimation::Forward);
    m_animation->start();

    QTimer::singleShot(3000,this,SLOT(slot_scene4()));

}

void GraphicsView::slot_scene4()
{
    flower->setVisible(true);

}
