#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QAction>
#include <QtGui>
#include <QMenuBar>
#include <QMenu>
#include <Qt>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    //Menus
    QMenu *fileMenu;
    QMenu *helpMenu;
    //Actions
    QAction *quitAction;
    QAction *aboutAction;
    QAction *saveAction;
    QAction *cancelAction;
    QAction *openAction;
    QAction *newAction;
    QAction *aboutQtAction;
};
#endif // MAINWINDOW_H
