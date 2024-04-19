#include "adminlogin.h"
#include "./ui_adminlogin.h"

adminLogin::adminLogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::adminLogin)
{
    ui->setupUi(this);

    Dialog connection_;
    QSqlQueryModel *model = new QSqlQueryModel();
    connection_.connOpen();
    QSqlQuery *qry = new QSqlQuery(connection_.userDatabase);

    qry -> prepare("SELECT Title, Authors, Description, Category, Publisher, 'Publish Date', Price FROM BooksDataset");
    qry -> exec();
    model->setQuery(*qry);
    ui->adminTableView->setModel(model);
    connection_.connClose();
    qDebug() << (model->rowCount());


}

adminLogin::~adminLogin()
{
    delete ui;
}

void adminLogin::on_adminEditButton_clicked()
{
    Dialog connection_;
    QString title, author, description, category, publisher, date, price, url;
    int idx;

    title = ui->adminTitleLineEdit->text();
    author = ui->adminAuthorsLineEdit->text();
    description = ui->adminDescriptionLineEdit->text();
    category = ui->adminCategoryLineEdit->text();
    publisher = ui->adminPublisherLineEdit->text();
    date = ui->adminPublisDateLineEdit->text();
    price = ui->adminPriceLineEdit->text();
    url = ui->adminUrlLineEdit->text();

    idx = ui->adminIndexLineEdit->text().toInt() - 1;

    connection_.connOpen();
    QString queryString = "UPDATE BooksDataset SET ";
    QStringList setValues;
    if (!title.isEmpty()) {
        setValues << "Title = :title";
    }

    if (!author.isEmpty()) {
        setValues << "Authors = :author";
    }

    if (!description.isEmpty()) {
        setValues << "Description = :description";
    }

    if (!category.isEmpty()) {
        setValues << "Category = :category";
    }

    if (!publisher.isEmpty()) {
        setValues << "Publisher = :publisher";
    }

    if (!date.isEmpty()) {
        setValues << "'Publish Date' = :date";
    }

    if (!price.isEmpty()) {
        setValues << "Price = :price";
    }

    if (!url.isEmpty()) {
        setValues << "Url = :url";
    }

    queryString += setValues.join(", ");
    queryString += " WHERE ROWID = (SELECT ROWID FROM BooksDataset LIMIT 1 OFFSET :offset)";

    QSqlQuery qry;
    qry.prepare(queryString);

    if (!title.isEmpty()) {
        qry.bindValue(":title", title);
    }

    if (!author.isEmpty()) {
        qry.bindValue(":author", author);
    }

    if (!description.isEmpty()) {
        qry.bindValue(":description", description);
    }

    if (!category.isEmpty()) {
        qry.bindValue(":category", category);
    }

    if (!publisher.isEmpty()) {
        qry.bindValue(":publisher", publisher);
    }

    if (!date.isEmpty()) {
        qry.bindValue(":date", date);
    }

    if (!price.isEmpty()) {
        qry.bindValue(":price", price);
    }

    if (!url.isEmpty()) {
        qry.bindValue(":url", url);
    }

    qry.bindValue(":offset", idx);

    if (!qry.exec()) {
        qDebug() << "Query execution error:" << qry.lastError().text();
        QMessageBox::critical(this, "Error", "Failed to edit. Please try again later.");
        return;
    }
    qDebug() << queryString;
    QMessageBox::information(this, "Success", "Table Updated.");
    connection_.connClose();
}

void adminLogin::on_adminAddButton_clicked()
{
    Dialog connection_;
    QString title, author, description, category, publisher, date, price, url;
    int idx;

    title = ui->adminTitleLineEdit->text();
    author = ui->adminAuthorsLineEdit->text();
    description = ui->adminDescriptionLineEdit->text();
    category = ui->adminCategoryLineEdit->text();
    publisher = ui->adminPublisherLineEdit->text();
    date = ui->adminPublisDateLineEdit->text();
    price = ui->adminPriceLineEdit->text();
    url = ui->adminUrlLineEdit->text();

    idx = ui->adminIndexLineEdit->text().toInt() - 1;

    connection_.connOpen();
    QSqlQuery qry;

    qry.prepare("INSERT INTO BooksDataset (Title, Authors, Description, Category, Publisher, \"Publish Date\", Price, Url) VALUES (:title, :author, :description, :category, :publisher, :date, :price, :url)");
    qry.bindValue(":title", title);
    qry.bindValue(":author", author);
    qry.bindValue(":description", description);
    qry.bindValue(":category", category);
    qry.bindValue(":publisher", publisher);
    qry.bindValue(":date", date);
    qry.bindValue(":price", price);
    qry.bindValue(":url", url);

    if (!qry.exec()) {
        qDebug() << "Query execution error:" << qry.lastError().text();
        QMessageBox::critical(this, "Error", "Failed to add. Please try again later.");
        return;
    }

    QMessageBox::information(this, "Success", "Adding successful!");
    connection_.connClose();
}


void adminLogin::on_adminDeleteButton_clicked()
{
    int row_number = ui->adminIndexLineEdit->text().toInt() - 1;
    Dialog connection_;
    connection_.connOpen();
    QSqlQuery qry;
    qry.prepare("DELETE FROM BooksDataset WHERE ROWID = (SELECT ROWID FROM BooksDataset LIMIT 1 OFFSET :offset)");
    qry.bindValue(":offset", row_number);
    if (qry.exec()) {
        QMessageBox::critical(this, tr("Delete"), tr("Deleted"));
    } else {
        QMessageBox::critical(this, tr("Error"), qry.lastError().text());
    }
    connection_.connClose();
}

void adminLogin::on_adminResetButton_clicked()
{
    Dialog connection_;
    QSqlQueryModel *model = new QSqlQueryModel();
    connection_.connOpen();
    QSqlQuery *qry = new QSqlQuery(connection_.userDatabase);

    qry -> prepare("SELECT Title, Authors, Description, Category, Publisher, 'Publish Date', Price FROM BooksDataset");
    qry -> exec();
    model->setQuery(*qry);
    ui->adminTableView->setModel(model);
    connection_.connClose();
    qDebug() << (model->rowCount());
}


void adminLogin::on_adminBuyButton_clicked()
{
    int row_number = ui->adminIndexLineEdit->text().toInt() - 1;
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


void adminLogin::on_adminTableView_clicked(const QModelIndex &index)
{
    int id = index.row();
    qDebug() << "Clicked row ID:" << id;
    QString idString = QString::number(id+1);
    ui->adminIndexLineEdit->setText(idString);
}


void adminLogin::on_searchButton_clicked()
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
        ui->adminTableView->setModel(model);
        connection_.connClose();
        qDebug() << (model->rowCount());

    } else {
        QMessageBox::information(this, "Information", "No information.");
    }

}

