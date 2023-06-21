#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDir>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void goBack();
    void goForward();
    void loadDirectory(QString directoryPath);

private:
    Ui::MainWindow *ui;
    QString initialPath;
    QVector<QString> history;
    int historyIndex;
};

#endif // MAINWINDOW_H
