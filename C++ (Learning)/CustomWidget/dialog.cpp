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

void Dialog::on_convertToPieButton_clicked()
{
    if (!ui->lineEdit->text().isEmpty()) {
        for (const QString& number : ui->lineEdit->text()) {
            data_.append(number.toDouble());
        }
    piechart.creatingPieChart(data_);
    }
}

