#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QMessageBox>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlDatabase>
#include <QSqlError>


namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();
    void setDatabaseConnection(QSqlDatabase dbConnection);

private slots:
    void on_submitReg_clicked();

private:
    Ui::Register *ui;
    QSqlDatabase userDatabaseRegister;
};

#endif // REGISTER_H
