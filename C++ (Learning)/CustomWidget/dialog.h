#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QVector>
#include <QLayout>

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
    QVector<unsigned> data_;
    ~Dialog();

private slots:
    void on_convertToPieButton_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
