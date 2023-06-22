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
    //setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    connect(ui->actionBack, &QAction::triggered, this, &MainWindow::goBack);
    connect(ui->actionForward, &QAction::triggered, this, &MainWindow::goForward);

    listDirectory(QDir::homePath());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::listDirectory(QString path, bool addToBackStack)
{
    if (addToBackStack) {
        if (!backStack.isEmpty() && path != backStack.top()) {
            forwardStack.clear();
        }
        backStack.push(path);
    }

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

        textButton->setText(QString("%1\nCreated: %2")
           .arg(fileInfo.fileName())
           .arg(fileInfo.birthTime().toString()));

        connect(textButton, &QPushButton::clicked, [=](){
            if(fileInfo.isDir()) {
                listDirectory(fileInfo.absoluteFilePath());
            }
        });

        vbox->addWidget(iconLabel);
        vbox->addWidget(textButton);
        layout->addLayout(vbox, row, col);

        col++;
        if (col == 4) { // adjust this value to your desired column count
            col = 0;
            row++;
        }
    }
}


void MainWindow::goBack() {
    if(!backStack.isEmpty()) {
        forwardStack.push(backStack.pop());
        if (!backStack.isEmpty()) {
            listDirectory(backStack.top(), false);
        }
    }
}

void MainWindow::goForward() {
    if(!forwardStack.isEmpty()) {
        QString forwardPath = forwardStack.pop();
        backStack.push(forwardPath);
        listDirectory(forwardPath, false);
    }
}
