#include "Enrollment.h"
#include <iomanip>

Enrollment::Enrollment()
    : enrollmentId(""), studentId(""), courseId(""), status("PENDING"),
      enrollmentDate("2026-10-12"), semester(3) {}

Enrollment::Enrollment(string eId, string sId, string cId, string stat, string date, int sem)
    : enrollmentId(eId), studentId(sId), courseId(cId), status(stat),
      enrollmentDate(date), semester(sem) {}

Enrollment::~Enrollment() {}

void Enrollment::enroll(const string& eId, const string& sId, const string& cId, int sem) {
    enrollmentId = eId;
    studentId = sId;
    courseId = cId;
    status = "ENROLLED";
    enrollmentDate = "2026-10-12";
    semester = sem;
}

void Enrollment::drop() {
    status = "DROPPED";
}

void Enrollment::display() const {
    cout << left << setw(14) << enrollmentId
         << setw(16) << studentId
         << setw(14) << courseId
         << setw(14) << status
         << setw(14) << enrollmentDate
         << setw(8)  << semester;
}

void Enrollment::printSlip(const string& studentName, const string& courseTitle, int credits) const {
    cout << "\n============================================================\n";
    cout << "           INDUS UNIVERSITY - COURSE REGISTRATION SLIP      \n";
    cout << "============================================================\n";
    cout << "  Registration ID : " << enrollmentId << "\n";
    cout << "  Registration Date: " << enrollmentDate << "\n";
    cout << "  Semester         : " << semester << "\n";
    cout << "------------------------------------------------------------\n";
    cout << "  Student ID       : " << studentId << "\n";
    cout << "  Student Name     : " << studentName << "\n";
    cout << "------------------------------------------------------------\n";
    cout << "  Course Code      : " << courseId << "\n";
    cout << "  Course Title     : " << courseTitle << "\n";
    cout << "  Course Credits   : " << credits << "\n";
    cout << "  Enrollment Status: " << status << "\n";
    cout << "============================================================\n";
    cout << "  Status: Registration Confirmed & Stored Successfully!    \n";
    cout << "============================================================\n\n";
}

string Enrollment::getEnrollmentId() const {
    return enrollmentId;
}

string Enrollment::getStudentId() const {
    return studentId;
}

string Enrollment::getCourseId() const {
    return courseId;
}

string Enrollment::getStatus() const {
    return status;
}

string Enrollment::getEnrollmentDate() const {
    return enrollmentDate;
}

int Enrollment::getSemester() const {
    return semester;
}

void Enrollment::setStatus(const string& s) {
    status = s;
}

void Enrollment::setEnrollmentDate(const string& d) {
    enrollmentDate = d;
}

void Enrollment::setSemester(int sem) {
    semester = sem;
}
