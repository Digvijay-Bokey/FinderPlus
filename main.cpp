#include "mainwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QFile file(":/darktheme.qss");
    if (file.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(file.readAll());
        app.setStyleSheet(styleSheet);
    } else {
        // Log error or notify the user here
    }

    MainWindow mainWindow;
    mainWindow.show();
    return QApplication::exec();
}
