#ifndef MAINUI_H
#define MAINUI_H

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

namespace Ui {
class mainUi;
}

class mainUi : public QDialog
{
    Q_OBJECT

public:
    explicit mainUi(QWidget *parent = nullptr);
    ~mainUi();

private slots:
    // void on_loadButton_clicked();

    void on_deleteButton_clicked();

    void on_addButton_clicked();

    void on_updateButton_clicked();

    void on_searchButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_resetButton_clicked();

private:
    Ui::mainUi *ui;
};

#endif // MAINUI_H
