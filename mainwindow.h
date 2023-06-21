#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QFileSystemModel *model;
};


private:
    Ui::MainWindow *ui;
    QFileSystemModel *model;
    QPushButton *closeButton;  // Add this line

#endif // MAINWINDOW_H
