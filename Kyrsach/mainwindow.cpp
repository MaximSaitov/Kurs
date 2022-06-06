#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QImage>
#include <QPixmap>
#include <iostream>
#include <math.h>
#include <QSlider>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::F1()
{
    mkn = QFileDialog::getOpenFileName(0, "Open Dialog", "Image Files ;*.png; *.jpg; *.jpeg");
    ui->label->setPixmap(mkn);
    rak.load(mkn);
    sc.load(mkn);
    prop = QImage (sc);
    ui->label->setPixmap(rak);
    ui->label->setScaledContents(true);
    int pic = rak.width();
    int label = ui->label->width();
    double fac = double (label)/pic;
    ui->label->setFixedWidth(fac * ui->label->pixmap().width());
    ui->label->setFixedHeight(fac * ui->label->pixmap().height());
    ui->label->setPixmap(QPixmap::fromImage(prop));
    ui->label->setMaximumWidth(ui->label->pixmap().width());
    ui->label->setMaximumHeight(ui->label->pixmap().height());
}

void MainWindow::on_pushButton_clicked()
{
    F1();
}


void MainWindow::F2()
{
    QImage sct = sc;
    int X = sc.width()-1;
    int Y = sc.height()-1;
    for (int i = 1; i <X; i++){
        for (int j = 1; j<Y; j++){
          QColor col(prop.pixel(i,j));
          int r = 0;
          int g = 0;
          int b = 0;
          for (int z = -1; z < 2; z++){
              for (int x = -1; x < 2; x++){
                 int w = i + z;
                 int h = j + x;
                 QColor col(prop.pixel(w,h));
                 r = r + col.red();
                 g = g + col.green();
                 b = b + col.blue();

              }
          }
          r = cog * log(1 + r);
          g = cog * log(1 + g);
          b = cog * log(1 + b);
          col.setRgb(r,g,b,0);
          sct.setPixel(i,j,col.rgb());
    }
  }
    ui->label_2->setPixmap(QPixmap::fromImage(sct));
}

void MainWindow::on_pushButton_2_clicked()
{

    F2();
}
int cog;
void MainWindow::on_verticalSlider_valueChanged(int cog)
{

}

