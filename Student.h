#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person {
private:
    int semester;
    string department;
    int enrolledCredits;
    int maxCredits;

public:
    Student();
    Student(string sId, string n, string e, string c, int sem, string dept, int maxCred = 24);
    virtual ~Student();

    virtual void display() const override;
    virtual string getRole() const override;
    virtual int getMaxCredits() const override;

    void update(string newName, string newEmail, string newContact, int newSem, string newDept);

    string getStudentId() const;
    int getSemester() const;
    string getDepartment() const;
    int getEnrolledCredits() const;

    void setSemester(int s);
    void setDepartment(string d);
    void setEnrolledCredits(int c);
    void setMaxCredits(int m);

    bool canTakeCredits(int c) const;
    void addCredits(int c);
    void removeCredits(int c);
};

#endif
