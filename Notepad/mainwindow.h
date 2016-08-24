#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();

    void on_actionSave_as_triggered();

    void on_actionNew_file_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionAbout_triggered();

    void on_textEdit_textChanged();

private:
    Ui::MainWindow *ui;

    bool chang_file;

    QTextEdit textEdit;

    void closeEvent(QCloseEvent *bar);

    QString app_name;
    QString filesMask;
    QString FileName;

    int askToSave(const QString& title);

};

#endif // MAINWINDOW_H
