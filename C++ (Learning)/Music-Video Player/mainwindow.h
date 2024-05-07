#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultimedia>
#include <QtMultimediaWidgets>
#include <QtGui>
#include <QtCore>
#include <QtWidgets>
#include <QSoundEffect>
#include <QAudioOutput>


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

private slots:
    void durationChanged(qint64 duration);
    void positionChanged(qint64 duration);


    void on_actionOpen_triggered();

    void on_horizontalSliderDuration_valueChanged(int value);

    void on_horizontalSliderVolume_valueChanged(int value);

    void on_pushButtonPlay_clicked();

    void on_pushButtonStop_clicked();

    void on_pushButtonVolume_clicked();

    void on_pushButtonSeekBackward_clicked();

    void on_pushButtonSeekForward_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *Player;
    QVideoWidget *Video;
    QAudioOutput *audioOutput;
    qint64 mDuration;
    bool IS_PAUSE = true;
    bool IS_MUTED = false;

    void updateDuration(qint64 Duration);
};
#endif // MAINWINDOW_H
