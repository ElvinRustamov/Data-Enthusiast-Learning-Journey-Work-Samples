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
#include "mainui.h"


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
    QSqlDatabase employeeDatabase;

    void connClose() {
        employeeDatabase.close();
        employeeDatabase.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connOpen() {
        employeeDatabase = QSqlDatabase::addDatabase("QSQLITE");
        employeeDatabase.setDatabaseName("C:/Users/maham/Desktop/Qt Projects/EmployeeInformation/Database/employees.db");

        if (!employeeDatabase.open()) {
            qDebug() << "Failed.";
            return false;
        } else {
            qDebug() << "Successful.";
            return true;
        }
    }

private slots:
    void on_loginButton_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
