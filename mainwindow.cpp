#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QFileIconProvider>
#include <QPushButton>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
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
    ui->pathLabel->setText(path);

    QDir dir(path);
    QFileInfoList list = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::AllEntries);

    QWidget *widget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(widget);
    widget->setLayout(layout);
    ui->scrollArea->setWidget(widget);

    for(QFileInfo fileInfo : list) {
        QHBoxLayout *hbox = new QHBoxLayout();
        QLabel *iconLabel = new QLabel();
        QLabel *textLabel = new QLabel();

        auto icon = QFileIconProvider().icon(fileInfo);
        iconLabel->setPixmap(icon.pixmap(50, 50));

     textLabel->setText(QString("%1\nCreated: %2")
        .arg(fileInfo.fileName())
        .arg(fileInfo.birthTime().toString()));

        QPushButton *button = new QPushButton("Open");
        connect(button, &QPushButton::clicked, [=](){
            if(fileInfo.isDir()) {
                pathsStack.push(path);
                listDirectory(fileInfo.absoluteFilePath());
            }
        });

        hbox->addWidget(iconLabel);
        hbox->addWidget(textLabel);
        hbox->addWidget(button);
        hbox->addStretch(1);
        layout->addLayout(hbox);
    }
}

void MainWindow::goBack() {
    if(!pathsStack.isEmpty()) {
        listDirectory(pathsStack.pop());
    }
}

void MainWindow::goForward() {
    // future implementation...
}
