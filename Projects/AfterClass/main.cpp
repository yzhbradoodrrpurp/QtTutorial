//
// Created by 易治行 on 2025/7/17.
//
#include <QApplication>
#include <QObject>
#include "teacher.h"
#include "student.h"

int main(int argc, char* argv[]) {
    QCoreApplication* app = new QCoreApplication(argc, argv);

    Teacher* teacher = new Teacher();
    Student* student = new Student();

    QObject::connect(teacher, &Teacher::hungry, student, &Student::treat);

    teacher->class_over();

    return app->exec();
}