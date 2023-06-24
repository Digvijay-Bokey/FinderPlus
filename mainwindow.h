#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void listDirectory(QString path);
    void goBack();
    void goForward();
    void searchFiles();

private:
    Ui::MainWindow *ui;
    QStack<QString> backStack;
    QStack<QString> forwardStack;
    QString currentPath;
};

#endif // MAINWINDOW_H
