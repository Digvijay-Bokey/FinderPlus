#include "mainwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QFile file(":/darktheme.qss");
    if (file.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(file.readAll());

        styleSheet += "QScrollBar:horizontal {"
                      "border: none;"
                      "background: #282828;"
                      "height: 10px;"
                      "margin: 0px 0px 0px 0px;"
                      "border-radius: 5px;"
                      "}"
                      "QScrollBar::handle:horizontal {"
                      "background: #888;"
                      "min-width: 20px;"
                      "border-radius: 5px;"
                      "}"
                      "QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {"
                      "border: none;"
                      "background: none;"
                      "}"
                      "QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal {"
                      "background: none;"
                      "}";
        app.setStyleSheet(styleSheet);
    } else {
        // Log error or notify the user here
    }

    MainWindow mainWindow;
    mainWindow.show();
    return QApplication::exec();
}

