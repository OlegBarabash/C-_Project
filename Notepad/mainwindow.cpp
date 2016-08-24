#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),chang_file (false)
{
    ui->setupUi(this);

    app_name =  windowTitle( );

    filesMask = tr("Text Files (*.txt);; C++ Files (*.cpp *.h)");

}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::askToSave(const QString& title)
{
    QMessageBox exitMsg;
    exitMsg.setWindowTitle(app_name);
    exitMsg.setText(title);
    exitMsg.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    exitMsg.setDefaultButton(QMessageBox::Cancel);
    return exitMsg.exec();
}

void MainWindow::on_actionExit_triggered()
{
    if (chang_file)
    {
        switch( askToSave(tr("File are not saved. \nSave and exit?")) )
        {
        case QMessageBox::No:
            QApplication::instance()->quit();
            break;
        case QMessageBox::Yes:
            emit ui->actionSave->triggered();
            break;
        }
    }else
        QApplication::instance()->quit();
}

void MainWindow::closeEvent(QCloseEvent *bar)
{
    emit ui->actionExit->triggered();
    bar->ignore();
}


void MainWindow::on_actionNew_file_triggered()
{
    if(chang_file)
    {
        switch( askToSave(tr("File are not saved. \nDo you want to save it?")) )
        {
        case QMessageBox::Cancel:
            return;
            break;
        case QMessageBox::Yes:
            emit ui->actionSave->triggered();
            break;
        }
    }
    ui->textEdit->clear ();
    FileName = (tr(""));
}

void MainWindow::on_actionOpen_triggered()
{
    if(chang_file)
    {
        switch(askToSave(tr("File are not saved." "\nDo you want to save it?")))
        {
        case QMessageBox::Cancel:
            return;
            break;
        case QMessageBox::Yes:
            emit ui->actionSave->triggered();
            break;
        }
    }
    FileName = (QFileDialog::getOpenFileName(this, tr("Open File"), QString(), filesMask));

    if (!FileName.isEmpty())
    {
        QFile file(FileName);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(this, tr("Error"), QString(tr("Could not open file %1").arg(FileName)));
            return;
        }
        ui->textEdit->clear();
        QTextStream data(&file);
        ui->textEdit->setText(data.readAll());
        chang_file = false;
        file.close();
    }
}

void MainWindow::on_actionSave_triggered()
{
    if (!FileName.isEmpty())
    {
        QFile file(FileName);
        if (!file.open(QIODevice::WriteOnly))
        {
            QMessageBox::critical(this, tr("Error"), QString(tr("Could not write to file %1").arg(FileName)));
             emit ui->actionSave_as->triggered();
        } else
        {
            QTextStream stream(&file);
            stream << ui->textEdit->toPlainText();
            stream.flush();
            file.close();
            chang_file = false;
        }
    }else
    {
        emit ui->actionSave_as->triggered();
    }
}

void MainWindow::on_actionSave_as_triggered()
{
    QString fileName =
        QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text (*.txt)"));
    if(!fileName.isEmpty())
    {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly))
        {
            QTextStream stream(&file);
            stream << ui->textEdit->toPlainText();
            stream.flush();
            file.close();
        }
    }
    chang_file = false;
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox helpMsg;
    helpMsg.setIcon(QMessageBox::Information);
    helpMsg.setWindowTitle(tr("Help"));
    helpMsg.setText(tr("\"I can not help you!\""));
    helpMsg.setInformativeText(tr("\"MyNewNotepad\" is not finished program!"));
    helpMsg.setStandardButtons(QMessageBox::Ok);
    helpMsg.exec();
}

void MainWindow::on_textEdit_textChanged()
{
    chang_file = true;
}
