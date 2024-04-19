#include "register.h"
#include "ui_register.h"

Register::Register(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}
void Register::setDatabaseConnection(QSqlDatabase dbConnection)
{
    userDatabaseRegister = dbConnection;
}

void Register::on_submitReg_clicked()
{
    QString username_, password_, password_checker, role_;
    username_ = ui -> usernameRegLineEdit->text();
    password_ = ui -> passwordRegLineEdit->text();
    password_checker = ui -> passwordRegCheckLineEdit->text();
    role_ = "user";

    if (password_ != password_checker) {
        QMessageBox::warning(this, "Warning", "Passwords don't match!");
    } else {
        if (!userDatabaseRegister.isOpen()) {
            qDebug() << "Error, connection failed.";
            return;
        }

        QSqlQuery qry;
        // userDatabaseRegister.open();

        qry.prepare("SELECT username FROM userInformation WHERE username = :username");
        qry.bindValue(":username", username_);


        if (!qry.exec()) {
            qDebug() << "Query execution error:" << qry.lastError().text();
            QMessageBox::critical(this, "Error", "Failed to execute query. Please try again later.");
            return;
        }

        if (qry.next()) {
            QMessageBox::warning(this, "Warning", "Username already exists!");
            return;
        }
        // userDatabaseRegister.close();
        // userDatabaseRegister.open();
        qry.prepare("INSERT INTO userInformation (username, password, role) VALUES (:username, :password, :role)");
        qry.bindValue(":username", username_);
        qry.bindValue(":password", password_);
        qry.bindValue(":role", role_);

        if (!qry.exec()) {
            qDebug() << "Query execution error:" << qry.lastError().text();
            QMessageBox::critical(this, "Error", "Failed to register. Please try again later.");
            return;
        }

        QMessageBox::information(this, "Success", "Registration successful!");
        // userDatabaseRegister.close();
        this->hide();
    }
}

