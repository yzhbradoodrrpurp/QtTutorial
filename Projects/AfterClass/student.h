//
// Created by 易治行 on 2025/7/17.
//

#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>
#include <QString>

class Student: public QObject {
public:
    Student(QObject* parent=nullptr);
    ~Student();

public slots:
    void treat();
    void treat_chocolate();
};

#endif //STUDENT_H
