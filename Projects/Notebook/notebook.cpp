//
// Created by 易治行 on 2025/7/18.
//

#include "notebook.h"
#include <QDateTime> // to set up current time
#include <QTimer> // to update time in real time
#include <QAbstractSpinBox> // to cover unwanted buttons
#include <QString> // to use `QString`
#include <QFileDialog> // to open the file-selecting window
#include <QFile> // to open the file
#include <QTextStream>

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

void Notebook::import() {
    // select the name of wanted files according to their types
    QString fileName = QFileDialog::getOpenFileName(this, "Import a File", "", "Text Files (*.txt *.md *.py)");

    if (not fileName.isEmpty()) {
        QFile file(fileName); // import the file

        // open the file in read-only mode and text mode
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file); // use text stream to read the file
            ui.textEdit->setPlainText(in.readAll()); // redirect the content in text stream to `textEdit`
            file.close();
        }
    }
}

void Notebook::save(){
    // pick name to the file
    QString fileName = QFileDialog::getSaveFileName(this, "Save the File", "", "Text Files (*.txt *.md)");

    if (not fileName.isEmpty()) {
        QFile file(fileName); // create a file to store the content

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file); // create a stream to write the file
            out << ui.textEdit->toPlainText(); // write the content of `textEdit` into the stream
            file.close();
        }
    }
}

void Notebook::update_time() {
    ui.dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}