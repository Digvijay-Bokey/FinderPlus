#include <QApplication>
#include <QFileSystemModel>
#include <QTreeView>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QStatusBar>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Define a dark theme StyleSheet
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

    // Get the selection model from the tree view.
    QItemSelectionModel *selectionModel = tree.selectionModel();

    // When the current file selection changes, show the file path in the status bar.
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
