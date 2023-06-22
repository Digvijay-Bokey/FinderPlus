#include <QMainWindow>
#include <QStack>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void listDirectory(QString path);
    void goBack();
    void goForward();

private:
    Ui::MainWindow *ui;
    QStack<QString> backStack;
    QStack<QString> forwardStack;
    QString currentPath;
};
