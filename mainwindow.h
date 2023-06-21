#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void loadDirectory(QString directoryPath);
    void on_fileButton_clicked();
    void on_backButton_clicked();
    void on_forwardButton_clicked();

private:
    void updateNavigationButtons();
    Ui::MainWindow *ui;
    QVector<QString> history;
    int historyIndex;
};

#endif // MAINWINDOW_H
