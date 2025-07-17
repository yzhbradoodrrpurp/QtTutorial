//
// Created by 易治行 on 2025/7/17.
//

#ifndef QQLOGINSYSTEM_H
#define QQLOGINSYSTEM_H

#include <QWidget>

#include "ui_QQLoginSystem.h"

class QQLoginSystem: public QWidget {
    Q_OBJECT // Qt 的宏，启用信号与槽机制
public:
    QQLoginSystem(QWidget* parent = nullptr);
    ~QQLoginSystem();

private slots:
    void commit_clicked();
    void cancel_clicked();

private:
    Ui::Form ui;
};

#endif //QQLOGINSYSTEM_H
