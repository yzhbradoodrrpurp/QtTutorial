//
// Created by 易治行 on 2025/7/18.
//

#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include <QMainWindow>
#include "ui_notebook.h"

class Notebook: public QMainWindow {
    Q_OBJECT
public:
    Notebook(QMainWindow* parent=nullptr);
    ~Notebook();

public slots:
    void import();
    void save();

private:
    Ui::notebook ui;
};

#endif //NOTEBOOK_H
