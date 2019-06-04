#include "buttonmonitor.h"
#include <wiringPi.h>
#include <QTimer>

ButtonMonitor::ButtonMonitor(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    wiringPiSetupGpio();
    pinMode(Button1, INPUT);
    pinMode(Button2, INPUT);
    pinMode(Button3, INPUT);
    updatevalue();
    QTimer *timer = new QTimer(this);
    // Timer laeuft alle Time Milisekunden ab: Signal Timeout
    connect(timer, SIGNAL(timeout()), this, SLOT(updatevalue()));
    timer->start(Time);

}

void ButtonMonitor::updatevalue()
{
    int butt1 = digitalRead(Button1);
    int butt2 = digitalRead(Button2);
    int butt3 = digitalRead(Button3);

    b1->setText(" B1: 1 " + butt1);
    b2->setText(" B2: 1 " + butt2);
    b3->setText(" B3: 1 " + butt3);


    if(butt1 == 0)
    {
        b1->setStyleSheet("background-color: red; color: black;");
        b1->setText(" B1: 1 " + butt1);
    }
    else{
        b1->setStyleSheet("background-color: black; color: white;");
         b1->setText(" B1: 0 " + butt1);
    }

    if(butt2 == 0)
    {
        b2->setStyleSheet("background-color: red; color: black;");
        b2->setText(" B2: 1 " + butt2);
    }
    else{
        b2->setStyleSheet("background-color: black; color: white;");
         b2->setText(" B2: 0 " + butt2);
    }

    if(butt3 == 0)
    {
        b3->setStyleSheet("background-color: red; color: black;");
        b3->setText(" B3: 1 " + butt3);
    }
    else{
        b3->setStyleSheet("background-color: black; color: white;");
         b3->setText(" B3: 0 " + butt3);
    }






}
