#include <QMainWindow>
#include <QStack>
#include <QLineEdit>
#include <QPushButton>

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
    void searchFiles();

private:
    Ui::MainWindow *ui;
    QStack<QString> backStack;
    QStack<QString> forwardStack;
    QString currentPath;
    QLineEdit *searchInput;
    QPushButton *searchButton;
};
