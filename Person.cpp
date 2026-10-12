#include "Person.h"
#include <iomanip>

Person::Person() : id(""), name(""), email(""), contactNumber("") {}

Person::Person(string i, string n, string e, string c)
    : id(i), name(n), email(e), contactNumber(c) {}

Person::~Person() {}

void Person::display() const {
    cout << left << setw(12) << id
         << setw(22) << name
         << setw(26) << email
         << setw(16) << contactNumber;
}

string Person::getRole() const {
    return "Person";
}

int Person::getMaxCredits() const {
    return 0;
}

string Person::getId() const {
    return id;
}

string Person::getName() const {
    return name;
}

string Person::getEmail() const {
    return email;
}

string Person::getContactNumber() const {
    return contactNumber;
}

void Person::setId(string i) {
    id = i;
}

void Person::setName(string n) {
    name = n;
}

void Person::setEmail(string e) {
    email = e;
}

void Person::setContactNumber(string c) {
    contactNumber = c;
}
