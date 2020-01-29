#ifndef CONNECTIONWIZARDSQLITEPAGE_H
#define CONNECTIONWIZARDSQLITEPAGE_H

#include <QWizardPage>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QSqlDatabase>
#include <QLineEdit>

class ConnectionWizardSqlitePage : public QWizardPage
{
    Q_OBJECT

public:
    enum {
        Type_Mysql,
        Type_Sqlite
    };

    ConnectionWizardSqlitePage(QWidget* parent = nullptr);

    bool isComplete() const;

    int nextId() const override;

public slots:
    void showFileDialog();
    bool testConnection();

private:
    QLineEdit* filePathNameEdit = NULL;
    QSqlDatabase database;
};

#endif // CONNECTIONWIZARDSQLITEPAGE_H
