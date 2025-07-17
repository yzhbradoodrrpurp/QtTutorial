//
// Created by 易治行 on 2025/7/17.
//

#include "teacher.h"

Teacher::Teacher(QObject* parent): QObject(parent) {}

Teacher::~Teacher(){}

void Teacher::class_over() {
    hungry();
}
