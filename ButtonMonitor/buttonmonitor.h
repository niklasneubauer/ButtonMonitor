#ifndef BUTTONMONITOR_H
#define BUTTONMONITOR_H

#include "ui_buttonmonitor.h"

const int Button1 = 22; // Buttons definieren
const int Button2 = 27; // Buttons definieren
const int Button3 = 17; // Buttons definieren
const int Time = 100;   // Updatezeit 100 ms

class ButtonMonitor : public QWidget, private Ui::ButtonMonitor
{
    Q_OBJECT

public:
    explicit ButtonMonitor(QWidget *parent = 0);
private slots:
    void updatevalue();
};

#endif // BUTTONMONITOR_H
