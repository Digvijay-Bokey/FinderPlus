#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileIconProvider>
#include <QLabel>
#include <QScrollArea>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , initialPath(QDir::homePath())
{
    ui->setupUi(this);

    // Initialize history
    history.push_back(initialPath);
    historyIndex = 0;

    loadDirectory(initialPath);

    connect(ui->backButton, &QPushButton::clicked, this, &MainWindow::goBack);
    connect(ui->forwardButton, &QPushButton::clicked, this, &MainWindow::goForward);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::goBack() {
    if(historyIndex > 0) {
        historyIndex--;
        loadDirectory(history[historyIndex]);
    }
}

void MainWindow::goForward() {
    if(historyIndex < history.size() - 1) {
        historyIndex++;
        loadDirectory(history[historyIndex]);
    }
}

void MainWindow::loadDirectory(QString directoryPath) {
    QDir directory(directoryPath);
    auto files = directory.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);

    QWidget *widget = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;
    widget->setLayout(layout);

    for (const auto &file : files) {
        auto icon = QFileIconProvider().icon(file);
        QLabel *iconLabel = new QLabel;
        iconLabel->setPixmap(icon.pixmap(50, 50));
        layout->addWidget(iconLabel);

        QLabel *textLabel = new QLabel;
        textLabel->setText(QString("%1\nCreated: %2").arg(file.fileName()).arg(file.birthTime().toString()));
        layout->addWidget(textLabel);
    }

    ui->scrollArea->setWidget(widget);

    ui->backButton->setEnabled(historyIndex != 0);
    ui->forwardButton->setEnabled(historyIndex != history.size() - 1);

    ui->pathLabel->setText(directoryPath);
}
