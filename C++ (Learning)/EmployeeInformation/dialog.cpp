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


void Dialog::on_loginButton_clicked()
{
    QString username_, password_;
    username_ = ui->usernameLineEdit->text();
    password_ = ui->passwordLineEdit->text();

    connOpen();
    QSqlQuery qry;
    qry.prepare("SELECT * FROM EmployeesLoginInformation WHERE username = :name AND password = :pass");
    qry.bindValue(":name", username_);
    qry.bindValue(":pass", password_);

    if (qry.exec()) {
        if (qry.next()) {
            qDebug() << "Login successful";
            qry.finish();
            connClose();
            this -> hide();
            mainUi mainUi;
            mainUi.setModal(true);
            mainUi.exec();

        } else {
            QMessageBox::warning(this, "Warning", "Incorrect username or password.");
        }
}
}

