//
// Created by 易治行 on 2025/7/17.
//

#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher: public QObject {
    Q_OBJECT
public:
    Teacher(QObject* parent=nullptr);
    ~Teacher();

signals:
    void hungry();

public slots:
    void class_over();

};

#endif //TEACHER_H
