#ifndef USERLOGIN_H
#define USERLOGIN_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include "dialog.h"
#include <QDesktopServices>
#include <QUrl>
#include "search.h"


namespace Ui {
class userLogin;
}

class userLogin : public QDialog
{
    Q_OBJECT

public:
    explicit userLogin(QWidget *parent = nullptr);
    ~userLogin();

private slots:
    // void on_userLoginLoadButton_clicked();

    void on_userLoginBuyButton_clicked();

    void on_userLoginTableView_clicked(const QModelIndex &index);

    void on_searchButton_clicked();

    void on_resetButton_clicked();

private:
    Ui::userLogin *ui;
};

#endif // USERLOGIN_H
