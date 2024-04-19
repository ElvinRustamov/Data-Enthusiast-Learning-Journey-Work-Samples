#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_LoginButton_clicked()
{
    QString username_, password_;
    username_ = ui -> usernameLineEdit -> text();
    password_ = ui -> passwordLineEdit -> text();

    connOpen();
    if (!userDatabase.isOpen()) {
        qDebug() << "Error, connection failed.";
        return;
    }
    QString role = "";
    QSqlQuery qry_role;
    qry_role.prepare("SELECT role FROM userInformation WHERE username = :name");
    qry_role.bindValue(":name", username_);
    if (!qry_role.exec()) {
        qDebug() << "Error executing query:" << qry_role.lastError().text();
    }

    if (qry_role.next()) {
        role = qry_role.value(0).toString();
    }
    qry_role.finish();
    connClose();

    if (role == "user") {
        connOpen();
        QSqlQuery qry;
        qry.prepare("SELECT * FROM userInformation WHERE username = :name AND password = :pass");
        qry.bindValue(":name", username_);
        qry.bindValue(":pass", password_);

        if (qry.exec()) {
            if (qry.next()) {
                qDebug() << "Login successful";
                this -> hide();
                userLogin userLogin;
                userLogin.setModal(true);
                userLogin.exec();

            } else {
                QMessageBox::warning(this, "Warning", "Incorrect username or password.");
            }
            qry.finish();
            connClose();
        }

            }
    else {
        connOpen();
        QSqlQuery qry;
        qry.prepare("SELECT * FROM userInformation WHERE username = :name AND password = :pass");
        qry.bindValue(":name", username_);
        qry.bindValue(":pass", password_);

        if (qry.exec()) {
            if (qry.next()) {
                qDebug() << "Login successful";
                this -> hide();
                adminLogin adminLogin;
                adminLogin.setModal(true);
                adminLogin.exec();

            } else {
                QMessageBox::warning(this, "Warning", "Incorrect username or password.");
            }
            qry.finish();
            connClose();
        }
    }
}



void Dialog::on_registerButton_clicked()
{
    Register registerDialog;
    registerDialog.setDatabaseConnection(userDatabase);
    registerDialog.exec();
}

