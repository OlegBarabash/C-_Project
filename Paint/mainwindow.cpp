#include <QBuffer>
#include <QFileDialog>
#include <QString>
#include <QPixmap>
#include <QPainter>
#include <QMessageBox>
#include <QResizeEvent>
#include <QtDebug>
#include <QColorDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "canvas.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    vbl = new QVBoxLayout ();
    c = new Canvas;
    vbl->addWidget(c);
    ui->frame->setLayout(vbl);
    windowName = windowTitle();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    if(c->started)
    {
        switch ( saveMsg( tr( "File is not saved! \nDo you want to save it?" ) ) ) {
        case QMessageBox::Yes:
            on_actionSave_triggered();
            break;
        case QMessageBox::No:
            fileName = QFileDialog::getOpenFileName(this,
                tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));
            if(fileName.isEmpty() )
                return;
            c->openPic(fileName);
            break;
        }
    }
    else
    {
        fileName = QFileDialog::getOpenFileName(this,
            tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));
        if(fileName.isEmpty() )
            return;
        c->openPic(fileName);
    }
}

void MainWindow::on_actionSave_triggered()
{
    if(fileName.isEmpty())
    {
        on_actionSave_as_triggered();
    }
    else
    {
        c->savePic(fileName);
    }
}

void MainWindow::on_actionSave_as_triggered()
{
    fileName = QFileDialog::getSaveFileName(this,
          tr("Save File"),"image",tr("Images (*.png *.jpg *.bmp)"));
    c->savePic(fileName);
}

void MainWindow::on_actionNew_triggered()
{
    if(c->started)
    {
        switch( saveMsg( tr( "File is not saved! \nDo you want to save it?" ))) {
        case QMessageBox::Yes:
            on_actionSave_triggered();
            break;
        case QMessageBox::No:
            delete c;
            c = new Canvas;
            vbl->addWidget(c);
            ui->frame->setLayout(vbl);
            break;
        }
    }
    else
    {
        delete c;
        c = new Canvas;
        vbl->addWidget(c);
        ui->frame->setLayout(vbl);
        windowName = windowTitle();
    }
}

void MainWindow::on_actionExit_triggered()
{
    if (c->started)
    {
        switch( saveMsg(tr("File is not saved. \nSave it?")) )
        {
        case QMessageBox::No:
            qApp->quit();
            break;
        case QMessageBox::Yes:
            on_actionSave_triggered();
            break;
        }
    }else
        qApp->quit();
}

int MainWindow::saveMsg(const QString& msg)
{
    QMessageBox sMsg;
    sMsg.setWindowTitle(windowName);
    sMsg.setText(msg);
    sMsg.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    sMsg.setDefaultButton(QMessageBox::Cancel);
    return sMsg.exec();
}

void MainWindow::closeEvent(QCloseEvent * em)
{
    on_actionExit_triggered();
    em->ignore();
}

void MainWindow::on_actionRectangle_triggered()
{
    c->figDraw = 'r';
}

void MainWindow::on_actionPencel_triggered()
{
    c->figDraw = 'p';
}

void MainWindow::on_actionLine_triggered()
{
    c->figDraw = 'l';
}

void MainWindow::on_actionCircle_triggered()
{
    c->figDraw = 'c';
}

void MainWindow::on_actionGreen_triggered()
{
    c->pen.setColor("green");
    c->painter->setPen(c->pen);
}

void MainWindow::on_actionRed_triggered()
{
    c->pen.setColor("red");
    c->painter->setPen(c->pen);
}

void MainWindow::on_actionBlue_triggered()
{
    c->pen.setColor("blue");
    c->painter->setPen(c->pen);
}

void MainWindow::on_actionBlack_triggered()
{
    c->pen.setColor("black");
    c->painter->setPen(c->pen);
}

void MainWindow::on_actionFill_triggered()
{
    c->figDraw = 'f';
}

void MainWindow::on_actionSelect_triggered()
{
    c->pen.setColor(QColorDialog::getColor());
    c->painter->setPen(c->pen);
}

void MainWindow::on_action1p_triggered()
{
    c->pen.setWidth(1);
    c->painter->setPen(c->pen);
}

void MainWindow::on_action3p_triggered()
{
    c->pen.setWidth(3);
    c->painter->setPen(c->pen);
}

void MainWindow::on_action5p_triggered()
{
    c->pen.setWidth(5);
    c->painter->setPen(c->pen);
}

void MainWindow::on_actionText_triggered()
{
    c->figDraw = 't';
}

void MainWindow::on_actionBack_triggered()
{
    c->toBack();
}

void MainWindow::on_actionForward_triggered()
{
    c->toForw();
}

void MainWindow::on_actionEraser_triggered()
{
    c->figDraw = 'e';
    QPen col(c->pen);
    col.setWidth(5);
    col.setColor("white");
    c->painter->setPen(col);
}
