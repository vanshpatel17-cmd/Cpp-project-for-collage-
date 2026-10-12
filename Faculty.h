#ifndef FACULTY_H
#define FACULTY_H

#include "Person.h"

class Faculty : public Person {
private:
    string department;
    string designation;

public:
    Faculty();
    Faculty(string fId, string n, string e, string c, string dept, string desig);
    virtual ~Faculty();

    virtual void display() const override;
    virtual string getRole() const override;

    string getFacultyId() const;
    string getDepartment() const;
    string getDesignation() const;

    void setDepartment(string dept);
    void setDesignation(string desig);
};

#endif
