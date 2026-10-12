#include "Faculty.h"
#include <iomanip>

Faculty::Faculty()
    : Person("", "", "", ""), department("CSE"), designation("Assistant Professor") {}

Faculty::Faculty(string fId, string n, string e, string c, string dept, string desig)
    : Person(fId, n, e, c), department(dept), designation(desig) {}

Faculty::~Faculty() {}

void Faculty::display() const {
    cout << left << setw(14) << id
         << setw(22) << name
         << setw(18) << department
         << setw(22) << designation
         << setw(16) << contactNumber;
}

string Faculty::getRole() const {
    return "Faculty";
}

string Faculty::getFacultyId() const {
    return id;
}

string Faculty::getDepartment() const {
    return department;
}

string Faculty::getDesignation() const {
    return designation;
}

void Faculty::setDepartment(string dept) {
    department = dept;
}

void Faculty::setDesignation(string desig) {
    designation = desig;
}
