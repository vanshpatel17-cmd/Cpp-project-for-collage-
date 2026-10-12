#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

using namespace std;

class Person {
protected:
    string id;
    string name;
    string email;
    string contactNumber;

public:
    Person();
    Person(string i, string n, string e, string c);
    virtual ~Person();

    virtual void display() const;
    virtual string getRole() const;
    virtual int getMaxCredits() const;

    string getId() const;
    string getName() const;
    string getEmail() const;
    string getContactNumber() const;

    void setId(string i);
    void setName(string n);
    void setEmail(string e);
    void setContactNumber(string c);
};

#endif
