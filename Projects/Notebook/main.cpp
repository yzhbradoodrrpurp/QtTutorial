//
// Created by 易治行 on 2025/7/18.
//
#include <QApplication>
#include "notebook.h"

int main(int argc, char* argv[]) {
    QApplication* app = new QApplication(argc, argv);

    Notebook* nb = new Notebook();
    nb->show();

    return app->exec();
}