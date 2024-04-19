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

void Dialog::on_createClientPushButton_clicked()
{
    std::vector<tcpclient*> clients;

    tcpclient *client = new tcpclient(this);

    clients.push_back(client);

    client->show();

}

