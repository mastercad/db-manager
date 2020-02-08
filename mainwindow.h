#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "newconnectionwindow.h"
#include "connectionfactory.h"
#include "connection.h"
#include "connections.h"
#include "connectioninfofactory.h"
#include "connectioninfo.h"

#include <QMainWindow>
#include <QObjectData>
#include <QSqlDatabase>
#include <QStandardItemModel>
#include <QCompleter>

class QTreeModel;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void openNewConnectionWindow();
    void openConnectionManagerWindow();
    void onEstablishNewConnection(QAction* action);
    void onQueryResultHeaderClicked(QStandardItem* item);
    void onExecuteQueryClicked();
    void createConnectionSubMenu();
    void saveConnectionInfos();
    void handleConnectionError(QString errorMessage);

private:
    Ui::MainWindow *ui;
    void handleDatabaseClicked(QModelIndex index);
    void handleTableClicked(QStandardItem* item);
    bool switchDatabase(QString databaseName);
    void collectTableInformations();
    void storeConnectionInfo(ConnectionInfo* connectionInfo);
    void loadConnectionInfos();
    Connection* establishNewConnection(ConnectionInfo* connectionInfo);

    QString generateLastExecutedQuery(const QSqlQuery& query);
    QSqlQuery sendQuery(QSqlQuery query);
    QSqlQuery sendQuery(QString queryString);

    NewConnectionWindow* newConnectionWindow = nullptr;
    Connection* dbConnection = nullptr;
    ConnectionInfo* connectionInfo= nullptr;

    QString activeDatabase;
    QString activeTable;

    ConnectionFactory* connectionFactory = nullptr;
    ConnectionInfoFactory* connectionInfoFactory = nullptr;

//    QMap<QString, QMap<QString, ConnectionInfo*> > connections;
    Connections connections;
    QMap<QString, bool> keywords;
    uint lastQueryTime = 0;
    QCompleter* completer = nullptr;
    bool connectionsSaved = true;
};

#endif // MAINWINDOW_H
