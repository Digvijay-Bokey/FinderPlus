#include "mainWindow.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent),
          window(new QWidget),
          mainLayout(new QVBoxLayout),
          layout(new QHBoxLayout),
          listWidget(new QListWidget),
          stackedWidget(new QStackedWidget),
          model(new QFileSystemModel),
          tree(new QTreeView) {

    QFile styleSheetFile(":/darktheme.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    qApp->setStyleSheet(styleSheet);

    listWidget->addItem("Home");
    listWidget->addItem("Search");
    listWidget->addItem("Your Library");

    model->setRootPath(QDir::currentPath());
    tree->setModel(model);
    tree->setRootIndex(model->index(QDir::currentPath()));

    stackedWidget->addWidget(tree);

    QObject::connect(listWidget, &QListWidget::currentRowChanged, stackedWidget, &QStackedWidget::setCurrentIndex);

    layout->addWidget(listWidget);
    layout->addWidget(stackedWidget);

    mainLayout->addLayout(layout);
    window->setLayout(mainLayout);

    setCentralWidget(window);
}
