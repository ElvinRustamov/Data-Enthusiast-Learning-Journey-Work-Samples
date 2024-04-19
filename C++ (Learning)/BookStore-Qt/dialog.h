#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include  "adminlogin.h"
#include "register.h"
#include "userlogin.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    QSqlDatabase userDatabase;

    void connClose() {
        userDatabase.close();
        userDatabase.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connOpen() {
        userDatabase = QSqlDatabase::addDatabase("QSQLITE");
        userDatabase.setDatabaseName("C:/Users/maham/Desktop/Qt Projects/BookStore-Qt/Database/users.db");

        if (!userDatabase.open()) {
            qDebug() << "Failed.";
            return false;
        } else {
            qDebug() << "Successful.";
            return true;
        }
    }

private slots:
    void on_LoginButton_clicked();

    void on_registerButton_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
