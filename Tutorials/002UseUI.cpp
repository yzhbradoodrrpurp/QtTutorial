//
// Created by 易治行 on 2025/7/17.
//

#include <QApplication>
#include <QWidget>
/*
 * 	包含由 Qt 的 uic 工具根据 002QQLoginSystem.ui 文件自动生成的头文件
 * 	该头文件中定义了一个类：Ui::Form，其中包含 .ui 文件中设计的所有控件的 C++ 指针，以及 setupUi() 方法
 */
#include "ui_002QQLoginSystem.h"


int main(int argc, char* argv[]) {
    // 创建图形界面必须
    QApplication app(argc, argv);

    // 根据 .ui 文件中创建窗口的类型定义 Widget
    QWidget *window = new QWidget();

    // 通过 `ui_002QQLoginSystem.h` 头文件中的 `Ui::Form` 加载该 ui
    Ui::QQLoginSystem ui;
    // 在 Widget 中设置该 ui
    ui.setupUi(window);
    // 显示出来
    window->show();

    return app.exec();
}