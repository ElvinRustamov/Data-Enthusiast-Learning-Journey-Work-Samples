#include "userlogin.h"
#include "ui_userlogin.h"

userLogin::userLogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::userLogin)
{
    ui->setupUi(this);
    Dialog connection_;
    QSqlQueryModel *model = new QSqlQueryModel();
    connection_.connOpen();
    QSqlQuery *qry = new QSqlQuery(connection_.userDatabase);

    qry -> prepare("SELECT Title, Authors, Description, Category, Publisher, 'Publish Date', Price FROM BooksDataset");
    qry -> exec();
    model->setQuery(*qry);
    ui->userLoginTableView->setModel(model);
    connection_.connClose();
    qDebug() << (model->rowCount());
}

userLogin::~userLogin()
{
    delete ui;
}

void userLogin::on_userLoginBuyButton_clicked()
{
    int row_number = ui->userLoginBuyLineEdit->text().toInt() - 1;
    Dialog connection_;
    connection_.connOpen();
    QSqlQuery qry;
    qry.prepare(QString("SELECT Url FROM BooksDataset LIMIT 1 OFFSET :idx"));
    qry.bindValue(":idx", row_number);

    if (!qry.exec()) {
        qDebug() << "Query execution error:" << qry.lastError().text();
        QMessageBox::critical(this, "Error", "Failed to execute query. Please try again later.");
        return;
    }

    if (qry.next()) {
        QString url = qry.value(0).toString();
        connection_.connClose();
        QDesktopServices::openUrl(QUrl(url));

    } else {
        QMessageBox::information(this, "Information", "No information.");
    }
}

void userLogin::on_userLoginTableView_clicked(const QModelIndex &index)
{
    int id = index.row();
    qDebug() << "Clicked row ID:" << id;
    QString idString = QString::number(id+1);
    ui->userLoginBuyLineEdit->setText(idString);
}


void userLogin::on_searchButton_clicked()
{
    search search_;
    search_.setModal(true);
    search_.exec();

    QString title, author, category, publisher;
    title = search_.getTitleSearch();
    author = search_.getAuthorSearch();
    category = search_.getCategorySearch();
    publisher = search_.getPublisherSearch();

    Dialog connection_;
    connection_.connOpen();
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(connection_.userDatabase);
    QString queryString = "SELECT Title, Authors, Description, Category, Publisher, 'Publish Date', Price FROM BooksDataset WHERE 1=1";

    if (!title.isEmpty()) {
        queryString += " AND Title LIKE :title";
    }

    if (!author.isEmpty()) {
        queryString += " AND Authors LIKE :author";
    }

    if (!category.isEmpty()) {
        queryString += " AND Category LIKE :category";
    }

    if (!publisher.isEmpty()) {
        queryString += " AND Publisher LIKE :publisher";
    }

    qry->prepare(queryString);
    if (!title.isEmpty()) {
        qry->bindValue(":title", "%" + title + "%");
    }

    if (!author.isEmpty()) {
        qry->bindValue(":author", "%" + author + "%");
    }

    if (!category.isEmpty()) {
        qry->bindValue(":category", "%" + category + "%");
    }

    if (!publisher.isEmpty()) {
        qry->bindValue(":publisher", "%" + publisher + "%");
    }

    if (!qry->exec()) {
        qDebug() << "Query execution error:" << qry->lastError().text();
        QMessageBox::critical(this, "Error", "Failed to execute query. Please try again later.");
        connection_.connClose();
        return;
    }

    if (qry->next()) {
        model->setQuery(*qry);
        ui->userLoginTableView->setModel(model);
        connection_.connClose();
        qDebug() << (model->rowCount());

    } else {
        QMessageBox::information(this, "Information", "No information.");
    }

}


void userLogin::on_resetButton_clicked()
{
    Dialog connection_;
    QSqlQueryModel *model = new QSqlQueryModel();
    connection_.connOpen();
    QSqlQuery *qry = new QSqlQuery(connection_.userDatabase);

    qry -> prepare("SELECT Title, Authors, Description, Category, Publisher, 'Publish Date', Price FROM BooksDataset");
    qry -> exec();
    model->setQuery(*qry);
    ui->userLoginTableView->setModel(model);
    connection_.connClose();
    qDebug() << (model->rowCount());
}

