//
// Created by 易治行 on 2025/7/18.
//

#include "notebook.h"
#include <QDateTime>
#include <QTimer>
#include <QAbstractSpinBox>

Notebook::Notebook(QMainWindow* parent): QMainWindow(parent) {
    // load UI
    ui.setupUi(this);

    // set `dateTimeEdit` as readable only
    ui.dateTimeEdit->setReadOnly(true);
    // remove the up and down buttons from `dateTimeEdit`
    ui.dateTimeEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);

    // create a timer which sends out a signal every minute
    QTimer* timer = new QTimer(this);
    timer->start(1000);

    // connect the timer to `update_time` function which executes the updating time behavior
    connect(timer, &QTimer::timeout, this, &Notebook::update_time);
    connect(ui.savePushButton, &QPushButton::clicked, this, &Notebook::save);
    connect(ui.importPushButton, &QPushButton::clicked, this, &Notebook::import);


}

Notebook::~Notebook() {}

void Notebook::import(){}

void Notebook::save(){}

void Notebook::update_time() {
    ui.dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}