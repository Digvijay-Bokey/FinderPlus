#include <QApplication>
#include <QFileSystemModel>
#include <QTreeView>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QStatusBar>
#include <QListWidget>
#include <QStackedWidget>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QFile styleSheetFile(":/darktheme.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    app.setStyleSheet(styleSheet);

    QMainWindow mainWindow;
    QWidget *window = new QWidget;
    QVBoxLayout *
