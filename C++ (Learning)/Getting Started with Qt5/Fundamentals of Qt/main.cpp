#include "dialog.h"

#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QLineEdit>
#include <QDateTimeEdit>
#include <QSpinBox>
#include <QComboBox>
#include <QStringList>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDial>
#include <QLCDNumber>
#include <QSlider>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Dialog w;
    // w.show();


    // QLabel label("Hello World!");
    // label.setStyleSheet("Qlabel:hover {color: rgb(60, 179, 113)}");
    // label.show();


    // QPushButton button_1(QIcon("filesaveas.png"), "Push Me");
    // button_1.setToolTip("Click this to turn back the hands of time");
    // button_1.show();


    // QString message = "'What do you know about this business?' the King said to Alice.\n'Nothing,' said Alice.\n'Nothing whatever?' persisted the King.\n'Nothing whatever,' said Alice.";
    // QLabel label(message);
    // label.setFont(QFont("Comic Sans MS", 18));
    // label.setAlignment(Qt::AlignCenter);
    // label.show();


    // QWidget *window = new QWidget;
    // QLabel *nameLabel = new QLabel("Open Happiness");
    // QLineEdit *firstNameLineEdit = new QLineEdit;
    // QLineEdit *secondNameLineEdit = new QLineEdit;
    // QSpinBox *ageSpinBox = new QSpinBox;
    // ageSpinBox -> setRange(1, 100);
    // QComboBox *employmentStatusComboBox = new QComboBox;
    // QStringList employmentStatus = {"Unemployed", "Employed", "NA"};
    // employmentStatusComboBox -> addItems(employmentStatus);

    // QGridLayout
    // QGridLayout *layout = new QGridLayout;
    // layout -> addWidget(nameLabel, 0, 0);
    // layout -> addWidget(firstNameLineEdit, 0, 1);
    // layout -> addWidget(secondNameLineEdit, 0, 2);
    // layout -> addWidget(ageSpinBox, 1, 0);
    // layout -> addWidget(employmentStatusComboBox, 1, 1, 1, 2);
    // window -> setLayout(layout);
    // window -> show();

    // QFormLayout
    // QFormLayout *personalInfoformLayout = new QFormLayout;
    // personalInfoformLayout -> addRow("First Name: ", firstNameLineEdit);
    // personalInfoformLayout -> addRow("Last Name: ", secondNameLineEdit);
    // personalInfoformLayout -> addRow("Age", ageSpinBox);
    // personalInfoformLayout -> addRow("Employment Status", employmentStatusComboBox);
    // window -> setLayout(personalInfoformLayout);
    // window -> show();

    // QVBoxLayout
    // QWidget *window = new QWidget;
    // QLabel *label1 = new QLabel("Username");
    // QLabel *label2 = new QLabel("Password");
    // QLineEdit *usernameLineEdit = new QLineEdit;
    // usernameLineEdit -> setPlaceholderText("Enter your username");
    // QLineEdit *passwordLineEdit = new QLineEdit;
    // passwordLineEdit -> setEchoMode(QLineEdit::Password);
    // passwordLineEdit -> setPlaceholderText("Enter your password");
    // QPushButton *button1 = new QPushButton("&Login");
    // QPushButton *button2 = new QPushButton("&Register");
    // QVBoxLayout *layout = new QVBoxLayout;
    // layout -> addWidget(label1);
    // layout -> addWidget(usernameLineEdit);
    // layout -> addWidget(label2);
    // layout -> addWidget(passwordLineEdit);
    // layout -> addWidget(button1);
    // layout -> addWidget(button2);
    // window -> setLayout(layout);
    // window -> show();

    //QHBoxLayout
    // QWidget *window = new QWidget;
    // QLineEdit *urlLineEdit = new QLineEdit;
    // QPushButton *exportButton = new QPushButton("Export");
    // urlLineEdit -> setPlaceholderText("Enter Url to export");
    // urlLineEdit -> setFixedWidth(400);
    // QHBoxLayout *layout = new QHBoxLayout;
    // layout -> addWidget(urlLineEdit);
    // layout -> addWidget(exportButton);
    // window -> setLayout(layout);
    // window -> show();


    // Chapter 3: Working with Signals and Slots
    // QPushButton *quitButton = new QPushButton("Quit");
    // QObject::connect(quitButton, SIGNAL(clicked(bool)), &a, SLOT(quit()));
    // quitButton -> show();

    // QWidget *window = new QWidget;
    // QVBoxLayout *layout = new QVBoxLayout;
    // QLabel *volumeLabel = new QLabel("0");
    // QDial *volumeDial = new QDial;
    // layout -> addWidget(volumeDial);
    // layout -> addWidget(volumeLabel);
    // QObject::connect(volumeDial, SIGNAL(valueChanged(int)), volumeLabel, SLOT(setNum(int)));
    // window -> setLayout(layout);
    // window -> show();

    // QWidget *window = new QWidget;
    // QVBoxLayout *layout = new QVBoxLayout;
    // QLabel *volumeLabel = new QLabel("0");
    // QDial *volumeDial = new QDial;
    // QSlider *lengthSlider = new QSlider(Qt::Horizontal);
    // QLCDNumber *volumeLCD = new QLCDNumber;
    // volumeLCD -> setPalette(Qt::red);
    // // volumeLabel -> setAlignment(Qt::AlignHCenter);
    // volumeDial -> setNotchesVisible(true);
    // volumeDial -> setMinimum(0);
    // volumeDial -> setMaximum(100);
    // lengthSlider -> setTickPosition(QSlider::TicksAbove);
    // lengthSlider -> setTickInterval(10);
    // lengthSlider -> setSingleStep(1);
    // lengthSlider -> setMinimum(0);
    // lengthSlider -> setMaximum(100);
    // layout -> addWidget(volumeDial);
    // // layout -> addWidget(volumeLabel);
    // layout -> addWidget(lengthSlider);
    // layout -> addWidget(volumeLCD);
    // // QObject::connect(volumeDial, SIGNAL(valueChanged(int)), volumeLabel, SLOT(setNum(int)));
    // // QObject::connect(volumeDial, SIGNAL(valueChanged(int)), volumeLCD, SLOT(display(int)));
    // QObject::connect(volumeDial, SIGNAL(valueChanged(int)), volumeLCD, SLOT(display(int)));
    // QObject::connect(lengthSlider, SIGNAL(valueChanged(int)), volumeLCD, SLOT(display(int)));
    // window -> setLayout(layout);
    // window -> show();
    return a.exec();
}
