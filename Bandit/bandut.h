#ifndef BANDUT_H
#define BANDUT_H

#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QWidget>
#include <QMessageBox>
#include <QFrame>
#include <QSize>

#include <QString>

class Bandut:public QWidget
{
    Q_OBJECT
public:
    Bandut();
private slots :
    void quit();
    void play();
    void doubel_M();
private:
    int money;
    int price;
    QLabel *label_2;
    QLabel *Price_label;
    QLabel *label;
    QLabel *score;
    QLabel *image_1;
    QLabel *image_2;
    QLabel *image_3;
    QPushButton *quitButton;
    QPushButton *doubelButton;
    QPushButton *playButton;
    QGridLayout *layout;
};



#endif // BANDUT_H
