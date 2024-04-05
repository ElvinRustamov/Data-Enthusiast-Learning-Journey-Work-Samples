#include "dialog.h"
#include "./ui_dialog.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QProgressBar>
#include <QDebug>
#include <QThread>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    progressBar = new QProgressBar(this);
    progressBar->setMinimum(0);
    progressBar->setMaximum(100);
    progressBar->setValue(0);

    ui->verticalLayout->addWidget(progressBar);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_browseSource_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Select file");
    if (!filePath.isEmpty()) {
        ui -> source -> setText(filePath);
    }
}

void Dialog::on_browseDestination_clicked()
{
    QString folderPath = QFileDialog::getExistingDirectory(this, "Select Folder");
    if (!folderPath.isEmpty()) {
        ui -> destination -> setText(folderPath);
    }
}


void Dialog::on_move_clicked()
{
    QString sourceFilePath = ui -> source ->text();
    QString destinationDirectoryPath = ui -> destination ->text();

    QFileInfo fileInfo(sourceFilePath);
    QString fileName = fileInfo.fileName();


    QString destinationFilePath = destinationDirectoryPath  + QDir::separator() + fileName;

    if (sourceFilePath == destinationFilePath) {
        QMessageBox::critical(this, "Error", "Paths are same");
        return;
    }


    moveFile(sourceFilePath, destinationFilePath);
}

void Dialog::moveFile(const QString& sourcePath, const QString& destinationPath)
{
    QFile sourceFile(sourcePath);
    QFile destinationFile(destinationPath);

    if (destinationFile.exists()) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "File Exists",
                                      "Destination file already exists. Do you want to overwrite it?",
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::No) {
            return;
        }
    }

    if (!sourceFile.exists()) {
        QMessageBox::critical(this, "Error", "Source file does not exist.");
        return;
    }

    if (!sourceFile.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Error", "Failed to open source file for reading.");
        return;
    }

    if (!destinationFile.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(this, "Error", "Failed to open destination file for writing.");
        return;
    }

    qint64 fileSize = sourceFile.size();
    qint64 bytesWritten = 0;

    while (!sourceFile.atEnd()) {
        QByteArray buffer = sourceFile.read(8192);
        bytesWritten += destinationFile.write(buffer);
        progressBar->setValue(static_cast<int>((bytesWritten * 100) / fileSize));
        qApp->processEvents();
    }

    sourceFile.close();
    destinationFile.close();

    if (!QFile::remove(sourcePath)) {
        QMessageBox::warning(this, "Warning", "Failed to remove the original file.");
    }

    QMessageBox::information(this, "Success", "File moved successfully.");

    accept();
}

