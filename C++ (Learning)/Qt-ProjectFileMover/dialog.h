#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QProgressBar>

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

private slots:
    void on_move_clicked();
    void on_browseSource_clicked();
    void on_browseDestination_clicked();

private:
    Ui::Dialog *ui;
    QProgressBar *progressBar;
    void moveFile(const QString& sourcePath, const QString& destinationPath);
};
#endif // DIALOG_H
