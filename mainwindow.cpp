#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QGridLayout>
#include <QDirIterator>
#include <QListWidget>
#include <QLabel>
#include <QFileInfoList>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    auto layout = new QGridLayout;

    QDirIterator it(QDir::currentPath(), QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        auto file = it.next();
        auto icon = QFileIconProvider().icon(QFileInfo(file));
        auto label = new QLabel;
        label->setPixmap(icon.pixmap(64, 64));
        layout->addWidget(label);
    }

    auto widget = new QWidget;
    widget->setLayout(layout);

    ui->scrollArea->setWidget(widget);

    QFile styleSheetFile(":/darktheme.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    qApp->setStyleSheet(styleSheet);
}

MainWindow::~MainWindow() {
    delete ui;
}
