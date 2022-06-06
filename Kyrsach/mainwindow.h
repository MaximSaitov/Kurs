#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void F1();

    void F2();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_verticalSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QImage prop;
    QImage sc;
    QPixmap rak;
    QString mkn;
    struct PixelColor{
        int r;
        int g;
        int b;
    };
public:
    int cog;

};
#endif // MAINWINDOW_H
