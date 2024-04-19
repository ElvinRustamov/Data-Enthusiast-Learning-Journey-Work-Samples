#ifndef SEARCH_H
#define SEARCH_H

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

namespace Ui {
class search;
}

class search : public QDialog
{
    Q_OBJECT

public:
    explicit search(QWidget *parent = nullptr);
    ~search();
    QString getTitleSearch() const;
    QString getAuthorSearch() const;
    QString getCategorySearch() const;
    QString getPublisherSearch() const;

private slots:
    void on_pushButton_clicked();

private:
    Ui::search *ui;
};

#endif // SEARCH_H
