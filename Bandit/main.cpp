#include "bandut.h"
#include <QApplication>
#include <ctime>

int main(int argc, char *argv[])
{
    srand(time(NULL));

    QApplication app(argc, argv);
    Bandut window;
    window.show();
    return app.exec();
}
