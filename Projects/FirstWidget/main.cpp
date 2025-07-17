//
// Created by 易治行 on 2025/7/17.
//
#include <QApplication>
#include "QQLoginSystem.h"

int  main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QQLoginSystem window;

    window.show();

    return app.exec();
}
