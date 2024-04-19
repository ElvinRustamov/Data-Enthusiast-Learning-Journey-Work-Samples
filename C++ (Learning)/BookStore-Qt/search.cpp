#include "search.h"
#include "ui_search.h"

search::search(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::search)
{
    ui->setupUi(this);
}

search::~search()
{
    delete ui;
}

QString search::getTitleSearch() const
{
    return ui->titleSearchLineEdit->text();
}

QString search::getAuthorSearch() const
{
    return ui->authorSearchLineEdit->text();
}

QString search::getCategorySearch() const
{
    return ui->categorySearchLineEdit->text();
}

QString search::getPublisherSearch() const
{
    return ui->publisherSearchLineEdit->text();
}

void search::on_pushButton_clicked()
{
    // This function is called when the button is clicked, but you aren't currently using the values retrieved from the UI.
    // If you want to use them elsewhere, you should assign them to member variables or emit signals to send them to other objects.
    QString titleSearch = ui->titleSearchLineEdit->text();
    QString authorSearch = ui->authorSearchLineEdit->text();
    QString categorySearch = ui->categorySearchLineEdit->text();
    QString publisherSearch = ui->publisherSearchLineEdit->text();
    this->hide();
}
