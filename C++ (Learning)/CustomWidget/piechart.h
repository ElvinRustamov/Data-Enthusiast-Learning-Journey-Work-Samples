#ifndef PIECHART_H
#define PIECHART_H

#include <QObject>
#include <QWidget>
#include <QVector>
#include <QColor>

class piechart : public QWidget
{
    Q_OBJECT
public:
    explicit piechart(QWidget *parent = nullptr);
    void creatingPieChart(QVector<unsigned> data_);


private slots:
   QVector<QColor> generateColors(int count);

signals:
};

#endif // PIECHART_H
