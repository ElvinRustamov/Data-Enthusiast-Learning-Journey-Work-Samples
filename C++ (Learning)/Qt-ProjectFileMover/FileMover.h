#ifndef FILEMOVER_H
#define FILEMOVER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {class FileMover;}
QT_END_NAMESPACE


class FileMover: public QMainWindow {
    Q_OBJECT
public:
    FileMover(QWidhet *parent = nullptr);
    ~FileMover();

private slots:
    void browseButton_clicked();
    void moveButton_clickled();

private:
    Ui::FileMover *ui;
};


#endif // FILEMOVER_H
