#ifndef SQLITECONNECTION_H
#define SQLITECONNECTION_H

#include "connection.h"

#include <QString>
#include <QPoint>
#include <QModelIndex>

class SqliteConnection : public Connection
{
private:
    void handleTableClicked(QModelIndex index);
    void loadDatabaseList();
    void loadTablesList();

public:
    void init();

public slots:
    void onListViewDoubleClicked(const QModelIndex index);
    void handleDatabaseContextMenuClicked(const QPoint& position);
    void handleResultTableContextMenuClicked(const QPoint& position);
    void truncateTable();
    void deleteTable();
    void renameTable();
    void copyResultViewSelection();
    void deleteResultViewSelection();
    void pasteToResultView();
    void insertNullToResultView();
};

#endif // SQLITECONNECTION_H
