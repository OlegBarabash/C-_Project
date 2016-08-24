#include "bandut.h"
#include <cstdlib>



Bandut::Bandut()
{
    label = new QLabel("<b>You have</b>:");
    label->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    label->setMaximumHeight(20);
    label_2 = new QLabel("<b>Price</b>:");
    price = 10;
    Price_label = new QLabel;
    Price_label->setNum(price);
    Price_label->setFrameStyle(QFrame::Box );
    Price_label->setMaximumHeight(20);

    money = 190;
    score = new QLabel;
    score->setNum(money);
    score->setFrameStyle(QFrame::Box );
    score->setMaximumHeight(20);

    playButton = new QPushButton("&Play");
    doubelButton = new QPushButton("&Double");
    quitButton = new QPushButton("&Quit");

    QPixmap pixmap("../QtBandut/car.jpg");

    image_1 = new QLabel;
    image_1->setAlignment(Qt::AlignCenter);
    image_1->setPixmap(pixmap);

    image_3 = new QLabel;
    image_3->setAlignment(Qt::AlignCenter);
    image_3->setPixmap(pixmap);

    image_2 = new QLabel;
    image_2->setAlignment(Qt::AlignCenter);
    image_2->setPixmap(pixmap);

    playButton->setMinimumSize(80,50);
    playButton->setMaximumSize(160,100);

    layout = new QGridLayout;
    layout->addWidget(label,0,0);
    layout->addWidget(score,0,1,1,2);
    layout->addWidget(label_2,1,0);
    layout->addWidget(Price_label,1,1,1,2);
    layout->addWidget(playButton,3,2);
    layout->addWidget(doubelButton,3,1);
    layout->addWidget(quitButton,3,0);
    layout->addWidget(image_1,2,0);
    layout->addWidget(image_2,2,1);
    layout->addWidget(image_3,2,2);

    QObject::connect(playButton, SIGNAL(clicked()), this, SLOT(play()));
    QObject::connect(doubelButton, SIGNAL(clicked()), this, SLOT(doubel_M()));
    QObject::connect(quitButton, SIGNAL(clicked()), this, SLOT(quit()));

    setLayout(layout);

    setWindowTitle("Bandut");
}

void Bandut::quit()
{
    QMessageBox quitMsg;
    quitMsg.setWindowTitle("Bandut");
    quitMsg.setText("Do you really want to quit?");
    quitMsg.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    quitMsg.setDefaultButton(QMessageBox::Cancel);
    if (quitMsg.exec() == QMessageBox::Yes)
        close();
}

void Bandut::doubel_M()
{
    money -= price;
    score->setNum(money);
    price += price;
    Price_label->setNum(price);
}

void Bandut::play()
{
    int pic_box[3]={};

    for (int i=0; i<3; ++i)
    {
        pic_box[i] = rand() %5;
    }

    if(pic_box[0] == pic_box[1] && pic_box[1] == pic_box[2])
    {
        price *= 15;
        money += price;
        price = 10;
    }
    else
    {
        price = 10;
        money -= price;
    }

    Price_label->setNum(price);
    score->setNum(money);

    QPixmap pixmap0("../QtBandut/mercedes.png");
    QPixmap pixmap1("../QtBandut/citroen.png");
    QPixmap pixmap2("../QtBandut/honda.png");
    QPixmap pixmap3("../QtBandut/chevrolet.png");
    QPixmap pixmap4("../QtBandut/suzuki.png");

    switch (pic_box[0])
    {
    case 0:
        image_1->setPixmap(pixmap0);
        break;
    case 1:
        image_1->setPixmap(pixmap1);
        break;
    case 2:
        image_1->setPixmap(pixmap2);
        break;
    case 3:
        image_1->setPixmap(pixmap3);
        break;
    case 4:
        image_1->setPixmap(pixmap4);
        break;
    }

    switch (pic_box[1])
    {
    case 0:
        image_2->setPixmap(pixmap0);
        break;
    case 1:
        image_2->setPixmap(pixmap1);
        break;
    case 2:
        image_2->setPixmap(pixmap2);
        break;
    case 3:
        image_2->setPixmap(pixmap3);
        break;
    case 4:
        image_2->setPixmap(pixmap4);
        break;
    }

    switch (pic_box[2])
    {
    case 0:
        image_3->setPixmap(pixmap0);
        break;
    case 1:
        image_3->setPixmap(pixmap1);
        break;
    case 2:
        image_3->setPixmap(pixmap2);
        break;
    case 3:
        image_3->setPixmap(pixmap3);
        break;
    case 4:
        image_3->setPixmap(pixmap4);
        break;
    }
}
