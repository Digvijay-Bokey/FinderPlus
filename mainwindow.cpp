#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath());

    ui->treeView->setModel(model);
    ui->treeView->setRootIndex(model->index(QDir::currentPath()));

    ui->listWidget->addItem("Home");
    ui->listWidget->addItem("Search");
    ui->listWidget->addItem("Your Library");

    QObject::connect(ui->listWidget, &QListWidget::currentRowChanged, ui->stackedWidget, &QStackedWidget::setCurrentIndex);

    // Customize the UI
    QFile styleSheetFile(":/darktheme.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());

    // Set the stylesheet
    qApp->setStyleSheet(styleSheet);

    // Enable transparency
    setAttribute(Qt::WA_TranslucentBackground);
}

MainWindow::~MainWindow() {
    delete ui;
}
