#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFileSystemModel>
#include <QDir>
#include <QLabel>
#include <QGridLayout>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), historyIndex(-1) {
    ui->setupUi(this);
    loadDirectory(QDir::homePath());
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::loadDirectory(QString directoryPath) {
    QDir directory(directoryPath);
    auto list = directory.entryInfoList(QDir::NoDotAndDotDot | QDir::AllEntries);

    auto widget = new QWidget();
    auto layout = new QGridLayout(widget);

    int row = 0;
    int col = 0;

    for (const auto &fileInfo : list) {
        auto button = new QPushButton();
        button->setIcon(QIcon(fileInfo.absoluteFilePath()));
        button->setIconSize(QSize(100, 100));
        button->setFixedSize(QSize(120, 120));

        QString fileInfoString = fileInfo.fileName() + "\n" +
            fileInfo.lastModified().toString("yyyy-MM-dd hh:mm:ss");

        auto textLabel = new QLabel(fileInfoString);

        layout->addWidget(button, row, col, Qt::AlignCenter);
        layout->addWidget(textLabel, row+1, col, Qt::AlignCenter);

        col++;

        if (col == 4) {
            row += 2;
            col = 0;
        }
    }

    ui->scrollArea->setWidget(widget);
    ui->pathLabel->setText(directoryPath);

    if (history.empty() || history.last() != directoryPath) {
        history.append(directoryPath);
        historyIndex++;
    }

    updateNavigationButtons();
}

void MainWindow::on_fileButton_clicked() {
    QString directory = QFileDialog::getExistingDirectory(this, "Open a folder", QDir::homePath(), QFileDialog::ShowDirsOnly);
    if (!directory.isEmpty()) {
        loadDirectory(directory);
    }
}

void MainWindow::on_backButton_clicked() {
    if (historyIndex > 0) {
        historyIndex--;
        loadDirectory(history[historyIndex]);
    }
}

void MainWindow::on_forwardButton_clicked() {
    if (historyIndex < history.size() - 1) {
        historyIndex++;
        loadDirectory(history[historyIndex]);
    }
}

void MainWindow::updateNavigationButtons() {
    ui->backButton->setEnabled(historyIndex > 0);
    ui->forwardButton->setEnabled(historyIndex < history.size() - 1);
}
