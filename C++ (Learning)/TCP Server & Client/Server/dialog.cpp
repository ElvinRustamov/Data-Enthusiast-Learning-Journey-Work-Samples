#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    server = new QTcpServer(this);
    connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));
    if (!server->listen(QHostAddress::Any, 1234)) {
        qDebug() << "Server couldn't start";
    } else {
        qDebug() << "Server started";
    }

    tableModel = new QStandardItemModel(this);
    tableModel->setColumnCount(3);
    tableModel->setHorizontalHeaderLabels({"Name", "Message", "MD5"});

    ui->tableView->setModel(tableModel);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::newConnection() {
    QTcpSocket *clientSocket = server->nextPendingConnection();

    connect(clientSocket, &QTcpSocket::readyRead, [=](){
        QByteArray requestData = clientSocket->readAll();

        QDataStream in(&requestData, QIODevice::ReadOnly);
        QString name, message;
        in >> name >> message;

        QByteArray hash = QCryptographicHash::hash(message.toUtf8(), QCryptographicHash::Md5);
        QString md5 = QString(hash.toHex());

        clientSocket->write(md5.toUtf8());

        QString logMessage = QString("Name: %1, Message: %2, MD5: %3\n").arg(name, message, md5);

        clientData.append(std::make_tuple(name, message, md5));
        tableModel->appendRow({new QStandardItem(name), new QStandardItem(message), new QStandardItem(md5)});
    });

    connect(clientSocket, &QTcpSocket::disconnected, clientSocket, &QTcpSocket::deleteLater);
}
