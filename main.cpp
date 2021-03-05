#include <MainWindow.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow window;
    window.setFixedWidth(800);
    window.setFixedHeight(200);
    window.show();

    return app.exec();
}
