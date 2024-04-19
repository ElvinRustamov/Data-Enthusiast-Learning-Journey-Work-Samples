#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QDialog>
#include <QTcpSocket>
#include <QDataStream>

namespace Ui {
class tcpclient;
}

class tcpclient : public QDialog
{
    Q_OBJECT

public:
    explicit tcpclient(QWidget *parent = nullptr);
    ~tcpclient();

private slots:
    void on_connectPushButton_clicked();

    void on_exitPushButton_clicked();
    void displayError(QAbstractSocket::SocketError socketError);


    void on_convertButton_clicked();

private:
    Ui::tcpclient *ui;
    QTcpSocket *new_socket;
};

#endif // TCPCLIENT_H
