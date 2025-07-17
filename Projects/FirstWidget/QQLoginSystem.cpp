//
// Created by 易治行 on 2025/7/17.
//

#include "ui_QQLoginSystem.h"
#include "QQLoginSystem.h"

QQLoginSystem::QQLoginSystem(QWidget *parent): QWidget(parent) {
    // 将 Ui 加载到 Widget 中
    ui.setupUi(this);

    // 连接信号与槽，发出什么信号，什么槽进行响应
    connect(ui.id_lineEdit, &QLineEdit::returnPressed, this, &QQLoginSystem::commit_clicked);
    connect(ui.password_lineEdit, &QLineEdit::returnPressed, this, &QQLoginSystem::commit_clicked);
    connect(ui.cancel_button, &QPushButton::clicked, this, &QWidget::close);
}

QQLoginSystem::~QQLoginSystem() {}

void QQLoginSystem::commit_clicked() {

}

void QQLoginSystem::cancel_clicked() {

}


