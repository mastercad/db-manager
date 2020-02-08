#include "sqliteconnectioneditwidget.h"
#include "ui_sqliteconnectioneditwidget.h"

#include <QFileDialog>

SqliteConnectionEditWidget::SqliteConnectionEditWidget(ConnectionManager *parent, Connections* connections) :
    QWidget(parent),
    ui(new Ui::SqliteConnectionEditWidget),
    parent(parent),
    connections(connections)
{
    ui->setupUi(this);
    connect(this->ui->openFileDialog, SIGNAL(clicked(bool)), this, SLOT(showFileDialog()));
}

void SqliteConnectionEditWidget::parseConnectionInfo(ConnectionInfo *connectionInfo) {
    if ("SQLITE" != connectionInfo->getConnectionType()) {
        return;
    }

    currentConnectionInfo = connectionInfo;

    if (true == connectionInfo->isConnectionNameAutogenerated()) {
        this->ui->connectionNameEdit->setPlaceholderText(connectionInfo->getConnectionName());
    } else {
        this->ui->connectionNameEdit->setText(connectionInfo->getConnectionName());
    }
    this->ui->databasePathEdit->setText(connectionInfo->getDatabasePath());
}

void SqliteConnectionEditWidget::showFileDialog() {
    QFileDialog dialog(parent);
    dialog.setFileMode(QFileDialog::AnyFile);
    if (dialog.exec()) {
        this->ui->databasePathEdit->setText(dialog.selectedFiles()[0]);
    }
}

void SqliteConnectionEditWidget::save() {
    QString oldConnectionName = currentConnectionInfo->getConnectionName();

    if (!this->ui->connectionNameEdit->text().isEmpty()) {
        currentConnectionInfo->setConnectionName(this->ui->connectionNameEdit->text());
        currentConnectionInfo->setConnectionNameAutoGenerated(false);
    }

    // wenn der name der Connection geändert wurde, müssen wir diese connection auch in der collection neu hinterlegen!
    if (oldConnectionName != currentConnectionInfo->getConnectionName()) {
        ConnectionInfo* oldConnectionInfo = new ConnectionInfo;
        oldConnectionInfo->setConnectionName(oldConnectionName);
        oldConnectionInfo->setConnectionType(currentConnectionInfo->getConnectionType());
        connections->replace(oldConnectionInfo, currentConnectionInfo);
    }

    if (!this->ui->databasePathEdit->text().isEmpty()) {
        currentConnectionInfo->setDatabasePath(this->ui->databasePathEdit->text());
    }

    emit this->connections->changed();
}

SqliteConnectionEditWidget::~SqliteConnectionEditWidget() {
    delete ui;
}
