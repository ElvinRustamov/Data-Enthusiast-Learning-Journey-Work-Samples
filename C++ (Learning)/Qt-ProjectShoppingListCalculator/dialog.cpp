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

void Dialog::on_calculateCost_clicked()
{
    // Prices
    const float bread_price = 0.8;
    const float potato_price = 1.0;
    const float milk_price = 3.0;
    const float butter_price = 13.0;
    const float tomato_price = 1.5;
    const float egg_price = 0.1;

    // Amounts
    int bread_amount = ui->breadAmount->text().toInt();
    float potato_amount = ui->potatoAmount->text().toFloat();
    float milk_amount = ui->milkAmount->text().toFloat();
    int egg_amount = ui->eggsAmount->text().toInt();
    float butter_amount = ui->butterAmount->text().toFloat();
    float tomato_amount = ui->tomatoAmount->text().toFloat();


    if (bread_amount < 0 || potato_amount < 0 || milk_amount < 0 || egg_amount < 0 || butter_amount < 0 || tomato_amount < 0) {
        QMessageBox::warning(this, "Warning", "Amounts must be positive numeric values");
    } else {

    float total_cost = (bread_amount * bread_price) + (potato_amount * potato_price) + (milk_amount * milk_price) + (egg_amount * egg_price) + (butter_amount * butter_price) + (tomato_amount * tomato_price);

    QString message = "Total Cost: " + QString::number(total_cost) + "$" + "\n" +
                        "Shopping List: \n" + "Bread | Amount: " + QString::number(bread_amount) + " | " + "Cost: " + QString::number(bread_amount * bread_price) + "$" +
                        "\n" + "Potato | Kilos: " + QString::number(potato_amount) + " | " + "Cost: " + QString::number(potato_amount * potato_price) + "$" +
                        "\n" + "Milk | Kilos: " + QString::number(milk_amount) + " | " + "Cost: " + QString::number(milk_amount * milk_price) + "$" +
                        "\n" + "Egg | Amount: " + QString::number(egg_amount) + " | " + "Cost: " + QString::number(egg_amount * egg_price) + "$" +
                        "\n" + "Butter | Kilos: " + QString::number(butter_amount) + " | " + "Cost: " + QString::number(butter_amount * butter_price) + "$" +
                        "\n" + "Tomato | Kilos: " + QString::number(tomato_amount) + " | " + "Cost: " + QString::number(tomato_amount * tomato_price) + "$";

    QMessageBox::information(this, "Shopping Cost", message);

    }
}

