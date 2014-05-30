#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>

#include <QDirModel>
#include <QStringListModel>
#include <QStandardItemModel>

#include <QTreeView>
#include <QListView>
#include <QTableView>

#include <QStringList>

class Window : public QMainWindow
{
public:
    Window();
    void exempleDirModel();
    void exempleListModel();
};

#endif // WINDOW_H
