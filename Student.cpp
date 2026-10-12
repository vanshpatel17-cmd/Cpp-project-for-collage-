#include "Student.h"
#include <iomanip>

Student::Student()
    : Person("", "", "", ""), semester(1), department("CSE"), enrolledCredits(0), maxCredits(24) {}

Student::Student(string sId, string n, string e, string c, int sem, string dept, int maxCred)
    : Person(sId, n, e, c), semester(sem), department(dept), enrolledCredits(0), maxCredits(maxCred) {}

Student::~Student() {}

void Student::display() const {
    cout << left << setw(14) << id
         << setw(20) << name
         << setw(8)  << semester
         << setw(16) << department
         << setw(14) << (to_string(enrolledCredits) + "/" + to_string(maxCredits))
         << setw(16) << contactNumber;
}

string Student::getRole() const {
    return "Student";
}

int Student::getMaxCredits() const {
    return maxCredits;
}

void Student::update(string newName, string newEmail, string newContact, int newSem, string newDept) {
    if (!newName.empty()) name = newName;
    if (!newEmail.empty()) email = newEmail;
    if (!newContact.empty()) contactNumber = newContact;
    if (newSem > 0) semester = newSem;
    if (!newDept.empty()) department = newDept;
}

string Student::getStudentId() const {
    return id;
}

int Student::getSemester() const {
    return semester;
}

string Student::getDepartment() const {
    return department;
}

int Student::getEnrolledCredits() const {
    return enrolledCredits;
}

void Student::setSemester(int s) {
    semester = s;
}

void Student::setDepartment(string d) {
    department = d;
}

void Student::setEnrolledCredits(int c) {
    enrolledCredits = c;
}

void Student::setMaxCredits(int m) {
    maxCredits = m;
}

bool Student::canTakeCredits(int c) const {
    return (enrolledCredits + c <= maxCredits);
}

void Student::addCredits(int c) {
    enrolledCredits += c;
}

void Student::removeCredits(int c) {
    enrolledCredits -= c;
    if (enrolledCredits < 0) enrolledCredits = 0;
}
