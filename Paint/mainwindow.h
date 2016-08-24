#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>


#include "canvas.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int saveMsg(const QString& msg);
    void closeEvent(QCloseEvent *);
    //void slotTimer();


private slots:
    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionNew_triggered();

    void on_actionExit_triggered();

    void on_actionRectangle_triggered();

    void on_actionPencel_triggered();

    void on_actionLine_triggered();

    void on_actionCircle_triggered();

    void on_actionGreen_triggered();

    void on_actionRed_triggered();

    void on_actionBlue_triggered();

    void on_actionBlack_triggered();

    void on_actionFill_triggered();

    void on_actionSelect_triggered();

    void on_action3p_triggered();

    void on_action1p_triggered();

    void on_action5p_triggered();

    void on_actionText_triggered();

    void on_actionBack_triggered();

    void on_actionForward_triggered();

    void on_actionEraser_triggered();

private:
    Ui::MainWindow *ui;
    QVBoxLayout *vbl;
    Canvas* c;
    QString fileName;
    QString windowName;

};

#endif // MAINWINDOW_H
