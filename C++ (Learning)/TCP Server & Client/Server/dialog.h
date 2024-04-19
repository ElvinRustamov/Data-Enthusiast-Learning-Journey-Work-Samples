#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QTcpServer>
#include <QTcpSocket>
#include <QByteArray>
#include <QDebug>
#include <QCryptographicHash>
#include <QStandardItemModel>
#include <tuple>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
signals:

public slots:
    void newConnection();

private:
    Ui::Dialog *ui;
    QTcpServer *server;

    QList<std::tuple<QString, QString, QString>> clientData;
    QStandardItemModel *tableModel;
};
#endif // DIALOG_H
