#include "piechart.h"

#include <QPainter>
#include <cmath>
#include <random>

piechart::piechart(QWidget *parent)
    : QWidget{parent}
{}


QVector<QColor> piechart::generateColors(int count)
{
    QVector<QColor> colors;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);

    for (int i = 0; i < count; ++i)
    {
        QColor color(dis(gen), dis(gen), dis(gen));
        colors.append(color);
    }

    return colors;
}

void piechart::creatingPieChart(QVector<unsigned> data_)
{
    QPainter painter(this);

    double sum = 0;
    for (double value : data_)
        sum += value;

    if (sum == 0)
        return;

    QVector<QColor> colors = generateColors(data_.size());

    double startAngle = 0;
    int colorIndex = 0;

    for (int i = 0; i < data_.size(); ++i)
    {
        double angle = 360.0 * data_[i] / sum;
        painter.setBrush(colors[colorIndex]);
        painter.drawPie(rect(), int(startAngle * 16), int(angle * 16));
        startAngle += angle;
        colorIndex = (colorIndex + 1) % colors.size();
    }
}
