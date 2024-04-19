#ifndef ADMINLOGIN_H
#define ADMINLOGIN_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include "dialog.h"
#include <QDesktopServices>
#include <QUrl>
#include "search.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class adminLogin;
}
QT_END_NAMESPACE

class adminLogin : public QDialog
{
    Q_OBJECT

public:
    adminLogin(QWidget *parent = nullptr);
    ~adminLogin();

private slots:
    void on_adminEditButton_clicked();

    void on_adminAddButton_clicked();

    void on_adminDeleteButton_clicked();

    void on_adminResetButton_clicked();

    void on_adminBuyButton_clicked();

    void on_adminTableView_clicked(const QModelIndex &index);

    void on_searchButton_clicked();

private:
    Ui::adminLogin *ui;
};

#endif
