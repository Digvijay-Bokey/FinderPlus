#include <QApplication>
#include <QFileSystemModel>
#include <QTreeView>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QStatusBar>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);


    QFile styleSheetFile(":/darktheme.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    app.setStyleSheet(styleSheet);

    QMainWindow mainWindow;
    QWidget *window = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout;

    QFileSystemModel model;
    model.setRootPath(QDir::currentPath());

    QTreeView tree;
    tree.setModel(&model);


    QItemSelectionModel *selectionModel = tree.selectionModel();


    QObject::connect(selectionModel, &QItemSelectionModel::currentChanged, [&mainWindow, &model](const QModelIndex &current) {
        mainWindow.statusBar()->showMessage(model.filePath(current));
    });

    tree.setRootIndex(model.index(QDir::currentPath()));
    layout->addWidget(&tree);

    window->setLayout(layout);
    mainWindow.setCentralWidget(window);
    mainWindow.show();

    return app.exec();
}
