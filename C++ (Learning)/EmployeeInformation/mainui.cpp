#include "mainui.h"
#include "ui_mainui.h"

mainUi::mainUi(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainUi)
{
    ui->setupUi(this);
    Dialog connection_;
    QSqlQueryModel *model = new QSqlQueryModel();
    connection_.connOpen();
    QSqlQuery *qry = new QSqlQuery(connection_.employeeDatabase);

    qry -> prepare("SELECT * FROM EmployeesInformation");
    qry -> exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
    connection_.connClose();
    qDebug() << (model->rowCount());
}

mainUi::~mainUi()
{
    delete ui;
}

void mainUi::on_deleteButton_clicked()
{
    Dialog connection_;
    QString fin_number;
    fin_number = ui->deleteLineEdit->text();
    connection_.connOpen();
    QSqlQuery qry;
    qry.prepare("DELETE FROM EmployeesInformation WHERE FIN= :fin_");
    qry.bindValue(":fin_", fin_number);
    if (qry.exec()) {
        QMessageBox::critical(this, tr("Delete"), tr("Deleted"));
    } else {
        QMessageBox::critical(this, tr("Error"), qry.lastError().text());
    }
    connection_.connClose();

}


void mainUi::on_addButton_clicked()
{
    Dialog connection_;
    QString fin, name, surname, phone, jobTitle, address;
    int age;

    fin = ui->deleteLineEdit->text();
    name = ui->nameLineEditTable->text();
    surname = ui->surnameLineEditTable->text();
    phone = ui->phoneLineEditTable->text();
    jobTitle = ui->jobTitleLineEditTable->text();
    address = ui->addressLineEditTable->text();
    age = ui->ageLineEditTable->text().toInt();

    connection_.connOpen();
    QSqlQuery qry;

    qry.prepare("SELECT FIN FROM EmployeesInformation WHERE FIN = :fin");
    qry.bindValue(":FIN", fin);


    if (!qry.exec()) {
        qDebug() << "Query execution error:" << qry.lastError().text();
        QMessageBox::critical(this, "Error", "Failed to execute query. Please try again later.");
        return;
    }

    if (qry.next()) {
        QMessageBox::warning(this, "Warning", "Employee already exists!");
        return;
    }
    qry.finish();

    qry.prepare("INSERT INTO EmployeesInformation (FIN, Name, Surname, 'Phone Number', 'Job Title', Address, Age) VALUES (:fin, :name, :surname, :phone, :jobtitle, :address, :age)");
    qry.bindValue(":fin", fin);
    qry.bindValue(":name", name);
    qry.bindValue(":surname", surname);
    qry.bindValue(":phone", phone);
    qry.bindValue(":jobtitle", jobTitle);
    qry.bindValue(":address", address);
    qry.bindValue(":age", age);



    if (!qry.exec()) {
        qDebug() << "Query execution error:" << qry.lastError().text();
        QMessageBox::critical(this, "Error", "Failed to register. Please try again later.");
        return;
    }

    QMessageBox::information(this, "Success", "Registration successful!");
    connection_.connClose();
}



void mainUi::on_updateButton_clicked()
{
    Dialog connection_;
    QString fin, name, surname, phone, jobTitle, address;
    int age;

    fin = ui->deleteLineEdit->text();
    name = ui->nameLineEditTable->text();
    surname = ui->surnameLineEditTable->text();
    phone = ui->phoneLineEditTable->text();
    jobTitle = ui->jobTitleLineEditTable->text();
    address = ui->addressLineEditTable->text();
    age = ui->ageLineEditTable->text().toInt();

    connection_.connOpen();
    QString queryString = "UPDATE EmployeesInformation SET ";
    QStringList setValues;

    if (!name.isEmpty()) {
        setValues << "Name = :name";
    }

    if (!surname.isEmpty()) {
        setValues << "Surname = :surname";
    }

    if (!phone.isEmpty()) {
        setValues << "'Phone Number' = :phone";
    }

    if (!jobTitle.isEmpty()) {
        setValues << "'Job Title' = :jobTitle";
    }

    if (!address.isEmpty()) {
        setValues << "Address = :address";
    }

    if (age != 0) {
        setValues << "Age = :age";
    }

    queryString += setValues.join(", ");
    queryString += " WHERE FIN = :fin";

    QSqlQuery qry;
    qry.prepare(queryString);

    if (!name.isEmpty()) {
        qry.bindValue(":name", name);
    }

    if (!surname.isEmpty()) {
        qry.bindValue(":surname", surname);
    }

    if (!phone.isEmpty()) {
        qry.bindValue(":phone", phone);
    }

    if (!jobTitle.isEmpty()) {
        qry.bindValue(":jobTitle", jobTitle);
    }

    if (!address.isEmpty()) {
        qry.bindValue(":address", address);
    }

    if (age != 0) {
        qry.bindValue(":age", age);
    }

    qry.bindValue(":fin", fin);

    if (!qry.exec()) {
        qDebug() << "Query execution error:" << qry.lastError().text();
        QMessageBox::critical(this, "Error", "Failed to register. Please try again later.");
        return;
    }
    qDebug() << queryString;
    QMessageBox::information(this, "Success", "Table Updated.");
    connection_.connClose();
}


void mainUi::on_searchButton_clicked()
{

    QString fin, name, surname, phone, jobTitle, address;
    int age;

    fin = ui->deleteLineEdit->text();
    name = ui->nameLineEditTable->text();
    surname = ui->surnameLineEditTable->text();
    phone = ui->phoneLineEditTable->text();
    jobTitle = ui->jobTitleLineEditTable->text();
    address = ui->addressLineEditTable->text();
    age = ui->ageLineEditTable->text().toInt();

    Dialog connection_;
    QSqlQueryModel *model = new QSqlQueryModel();
    connection_.connOpen();
    QSqlQuery *qry = new QSqlQuery(connection_.employeeDatabase);

    QString queryString = "SELECT * FROM EmployeesInformation WHERE 1=1";

    if (!fin.isEmpty()) {
        queryString += " AND FIN LIKE :fin";
    }

    if (!name.isEmpty()) {
        queryString += " AND Name LIKE :name";
    }

    if (!surname.isEmpty()) {
        queryString += " AND Surname LIKE :surname";
    }

    if (!phone.isEmpty()) {
        queryString += " AND [Phone Number] LIKE :phone";
    }

    if (!jobTitle.isEmpty()) {
        queryString += " AND [Job title] LIKE :jobTitle";
    }

    if (!address.isEmpty()) {
        queryString += " AND Address LIKE :address";
    }

    if (age != 0) {
        queryString += " AND Age = :age";
    }

    qry->prepare(queryString);
    if (!fin.isEmpty()) {
        qry->bindValue(":fin", "%" + fin + "%");
    }

    if (!name.isEmpty()) {
        qry->bindValue(":name", "%" + name + "%");
    }

    if (!surname.isEmpty()) {
        qry->bindValue(":surname", "%" + surname + "%");
    }

    if (!phone.isEmpty()) {
        qry->bindValue(":phone", "%" + phone + "%");
    }

    if (!jobTitle.isEmpty()) {
        qry->bindValue(":jobTitle", "%" + jobTitle + "%");
    }

    if (!address.isEmpty()) {
        qry->bindValue(":address", "%" + address + "%");
    }

    if (age != 0) {
        qry->bindValue(":age", age);
    }

    if (!qry->exec()) {
        qDebug() << "Query execution error:" << qry->lastError().text();
        QMessageBox::critical(this, "Error", "Failed to execute query. Please try again later.");
        connection_.connClose();
        return;
    }

    if (qry->next()) {
        model->setQuery(*qry);
        ui->tableView->setModel(model);
        connection_.connClose();
        qDebug() << (model->rowCount());

    } else {
        QMessageBox::information(this, "Information", "No information.");
    }
}


void mainUi::on_tableView_clicked(const QModelIndex &index)
{
    QString id = ui->tableView->model()->index(index.row(), 0).data().toString();
    qDebug() << "Clicked row ID:" << id;
    ui->deleteLineEdit->setText(id);
}


void mainUi::on_resetButton_clicked()
{
    Dialog connection_;
    QSqlQueryModel *model = new QSqlQueryModel();
    connection_.connOpen();
    QSqlQuery *qry = new QSqlQuery(connection_.employeeDatabase);

    qry -> prepare("SELECT * FROM EmployeesInformation");
    qry -> exec();
    model->setQuery(*qry);
    ui->tableView->setModel(model);
    connection_.connClose();
    qDebug() << (model->rowCount());
}

