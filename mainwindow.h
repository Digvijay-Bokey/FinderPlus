#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QTreeView>
#include <QListWidget>
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStatusBar>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    QWidget *window;
    QVBoxLayout *mainLayout;
    QHBoxLayout *layout;
    QListWidget *listWidget;
    QStackedWidget *stackedWidget;
    QFileSystemModel *model;
    QTreeView *tree;
};

#endif // MAINWINDOW_H
