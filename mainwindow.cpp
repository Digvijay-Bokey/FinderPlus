#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QFileIconProvider>
#include <QPushButton>
#include <QDateTime>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground);

    connect(ui->actionBack, &QAction::triggered, this, &MainWindow::goBack);
    connect(ui->actionForward, &QAction::triggered, this, &MainWindow::goForward);

    listDirectory(QDir::homePath());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::listDirectory(QString path)
{
    currentPath = path;
    ui->pathLabel->setText(path);

    QDir dir(path);
    QFileInfoList list = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::AllEntries);

    QWidget *widget = new QWidget;
    QGridLayout *layout = new QGridLayout(widget);
    widget->setLayout(layout);
    ui->scrollArea->setWidget(widget);

    int row = 0, col = 0;
    for(QFileInfo fileInfo : list) {
        QVBoxLayout *vbox = new QVBoxLayout();
        QLabel *iconLabel = new QLabel();
        QPushButton *textButton = new QPushButton();

        auto icon = QFileIconProvider().icon(fileInfo);
        iconLabel->setPixmap(icon.pixmap(50, 50));
        iconLabel->setAlignment(Qt::AlignCenter);

        textButton->setText(QString("%1\nCreated: %2")
            .arg(fileInfo.fileName())
            .arg(fileInfo.birthTime().toString()));
        textButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

        if(fileInfo.isDir()) {
            connect(textButton, &QPushButton::clicked, [=](){
                backStack.push(currentPath);
                forwardStack.clear();
                listDirectory(fileInfo.absoluteFilePath());
            });
        }

        vbox->addWidget(iconLabel);
        vbox->addWidget(textButton);
        vbox->setAlignment(Qt::AlignCenter);
        layout->addLayout(vbox, row, col);

        if(++col >= 4) {
            col = 0;
            row++;
        }
    }
}

void MainWindow::goBack() {
    if(!backStack.isEmpty()) {
        forwardStack.push(currentPath);
        listDirectory(backStack.pop());
    }
}

void MainWindow::goForward() {
    if(!forwardStack.isEmpty()) {
        backStack.push(currentPath);
        listDirectory(forwardStack.pop());
    }
}
