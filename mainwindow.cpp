#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QGridLayout>
#include <QDirIterator>
#include <QListWidget>
#include <QLabel>
#include <QFileInfoList>
#include <QFileIconProvider>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    auto layout = new QVBoxLayout;
    layout->setSpacing(10);

    QDirIterator it(QDir::currentPath(), QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        auto file = it.next();
        auto fileInfo = QFileInfo(file);
        auto icon = QFileIconProvider().icon(fileInfo);

        // Icon
        auto iconLabel = new QLabel;
        iconLabel->setPixmap(icon.pixmap(64, 64));

        // Name and date
        auto textLabel = new QLabel;
        textLabel->setText(QString("%1\nCreated: %2").arg(fileInfo.fileName()).arg(fileInfo.birthTime().toString()));
        textLabel->setStyleSheet("color: #d3d3d3;");

        // Box for icon and text
        auto box = new QWidget;
        box->setStyleSheet("background-color: #282828; border-radius: 10px; margin: 5px;");
        auto boxLayout = new QHBoxLayout;
        boxLayout->addWidget(iconLabel);
        boxLayout->addWidget(textLabel);
        boxLayout->setAlignment(Qt::AlignLeft); // Ensure items stay on the left side
        box->setLayout(boxLayout);

        layout->addWidget(box);
    }

    auto widget = new QWidget;
    widget->setLayout(layout);
    ui->scrollArea->setWidget(widget);

    // Adding the stylesheet
    QFile styleSheetFile(":/darktheme.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    qApp->setStyleSheet(styleSheet);
}

MainWindow::~MainWindow() {
    delete ui;
}
