#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Player = new QMediaPlayer();
    audioOutput = new QAudioOutput();

    ui->pushButtonPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    ui->pushButtonStop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
    ui->pushButtonSeekForward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));
    ui->pushButtonSeekBackward->setIcon(style()->standardIcon(QStyle::SP_MediaSeekBackward));
    ui->pushButtonVolume->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));

    ui->horizontalSliderVolume->setMinimum(0);
    ui->horizontalSliderVolume->setMaximum(100);
    ui->horizontalSliderVolume->setValue(30);

    audioOutput->setVolume(ui->horizontalSliderVolume->value());
    Player->setAudioOutput(audioOutput);

    connect(Player, &QMediaPlayer::durationChanged, this, &MainWindow::durationChanged);
    connect(Player, &QMediaPlayer::positionChanged, this, &MainWindow::positionChanged);

    ui->horizontalSliderDuration->setRange(0, Player->duration() / 1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::durationChanged(qint64 duration)
{
    mDuration = duration / 1000;
    ui->horizontalSliderDuration->setMaximum(mDuration);
}

void MainWindow::positionChanged(qint64 duration)
{
    if (!ui->horizontalSliderDuration->isSliderDown()) {
        ui->horizontalSliderDuration->setValue(duration / 1000);
        updateDuration(duration / 1000);
    }
}

void MainWindow::updateDuration(qint64 Duration)
{
    if (Duration || mDuration) {
        QTime CurrentTime((Duration / 3600) % 60, (Duration / 60) % 60, Duration % 60, (Duration * 1000) % 1000);
        QTime TotalTime((mDuration / 3600) % 60, (mDuration / 60) % 60, mDuration % 60,(mDuration * 1000) % 1000);
        QString Format = "";
        if (mDuration > 3600) {
            Format = "hh:mm:ss";
        } else {Format = "mm:ss";}
    ui->labelCurrentTime->setText(CurrentTime.toString(Format));
    ui->labelTotalTime->setText(TotalTime.toString(Format));

    }

}


void MainWindow::on_actionOpen_triggered()
{
    QString FileName = QFileDialog::getOpenFileName(this, tr("Select Video File"), "", tr("MP4 Files (*.mp4 *.mp3)"));
    Video = new QVideoWidget();
    Video->setGeometry(5, 5, ui->groupBox->width()-10, ui->groupBox->height()-10);
    Video->setParent(ui->groupBox);
    Player->setVideoOutput(Video);
    Player->setSource(QUrl::fromLocalFile(FileName));
    Video->setVisible(true);
    Video->show();
}


void MainWindow::on_horizontalSliderDuration_valueChanged(int value)
{
    Player->setPosition(value * 1000);

}


void MainWindow::on_horizontalSliderVolume_valueChanged(int value)
{

    audioOutput->setVolume(value);
    Player->setAudioOutput(audioOutput);
}


void MainWindow::on_pushButtonPlay_clicked()
{
    if (IS_PAUSE == true) {
        IS_PAUSE = false;
        Player->play();
        ui->pushButtonPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPause));

    }
    else {
        IS_PAUSE = true;
        Player->pause();
        ui->pushButtonPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));

    }
}


void MainWindow::on_pushButtonStop_clicked()
{
    Player->stop();
    if (IS_PAUSE == false) {
        ui->pushButtonPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    }
}

void MainWindow::on_pushButtonVolume_clicked()
{
    if (IS_MUTED == false) {
        IS_MUTED = true;
        ui->pushButtonVolume->setIcon(style()->standardIcon(QStyle::SP_MediaVolumeMuted));
        audioOutput->setMuted(true);
        Player->setAudioOutput(audioOutput);

    } else {
        IS_MUTED = false;
        ui->pushButtonVolume->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
        audioOutput->setMuted(false);
        Player->setAudioOutput(audioOutput);
    }
}


void MainWindow::on_pushButtonSeekBackward_clicked()
{
    ui->horizontalSliderDuration->setValue(ui->horizontalSliderDuration->value() - 20);
    Player->setPosition(ui->horizontalSliderDuration->value() * 1000);
}


void MainWindow::on_pushButtonSeekForward_clicked()
{
    ui->horizontalSliderDuration->setValue(ui->horizontalSliderDuration->value() + 20);
    Player->setPosition(ui->horizontalSliderDuration->value() * 1000);


}


