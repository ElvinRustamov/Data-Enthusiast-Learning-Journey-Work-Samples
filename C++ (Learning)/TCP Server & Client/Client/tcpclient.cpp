#include "tcpclient.h"
#include "ui_tcpclient.h"

tcpclient::tcpclient(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::tcpclient)
{
    ui->setupUi(this);

}

tcpclient::~tcpclient()
{
    delete ui;
}

void tcpclient::on_connectPushButton_clicked()
{
    QString ip_, client_name;
    int port_;

    client_name = ui->clientNameLineEdit->text();
    ip_ = ui->ipAddressLineEdit->text();
    port_ = ui->portLineEdit->text().toInt();
    qDebug() << ip_;
    qDebug() << port_;

    new_socket = new QTcpSocket(this);

    connect(new_socket, SIGNAL(errorOccurred(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));

    new_socket->connectToHost(ip_, port_);

    if (new_socket->isOpen()) {
        ui->clientNameLineEdit->setEnabled(false);
        ui->ipAddressLineEdit->setEnabled(false);
        ui->portLineEdit->setEnabled(false);
        ui->messageLineEdit->setEnabled(true);

        ui->connectPushButton->setEnabled(false);
        ui->convertButton->setEnabled(true);
    }

}

void tcpclient::displayError(QAbstractSocket::SocketError socketError)
{
    qDebug() << "Socket error:" << socketError;
}


void tcpclient::on_exitPushButton_clicked()
{
    if (new_socket->state() == QAbstractSocket::ConnectedState) {
        new_socket->disconnectFromHost();
        new_socket->waitForDisconnected();
    }

    close();
}


void tcpclient::on_convertButton_clicked()
{
    QString client_name, message;

    client_name = ui->clientNameLineEdit->text();
    message = ui->messageLineEdit->toPlainText();

    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    out << client_name << message;

    new_socket->write(data);
    new_socket->waitForBytesWritten();

    new_socket->waitForReadyRead();
    QByteArray responseData = new_socket->readAll();
    QString md5 = QString::fromUtf8(responseData);
    ui->md5LineEdit->setText(md5);

    new_socket->disconnectFromHost();
}

