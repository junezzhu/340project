#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Pirate Game!");
    setWindowIcon(QIcon(":/images/caomei.png"));

    WigglyWidget * wigglyWidget = new WigglyWidget;
    wigglyWidget->setText("����");
    scene.addWidget(wigglyWidget);

    ui->graphicsView->setAlignment( Qt::AlignCenter );
    ui->graphicsView->setScene(&scene);
    ui->graphicsView->setBackgroundBrush(QImage(":/images/hb2.jpg"));
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground);



    QImage img(":/images/hb2.jpg");
    this->resize(img.size());

    scene.setSceneRect(-100,-100,100,100);
}

MainWindow::~MainWindow()
{
    delete ui;
}
