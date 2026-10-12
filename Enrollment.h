#ifndef ENROLLMENT_H
#define ENROLLMENT_H

#include <string>
#include <iostream>

using namespace std;

class Enrollment {
private:
    string enrollmentId;
    string studentId;
    string courseId;
    string status;
    string enrollmentDate;
    int semester;

public:
    Enrollment();
    Enrollment(string eId, string sId, string cId, string stat = "ENROLLED", string date = "2026-10-12", int sem = 3);
    ~Enrollment();

    void enroll(const string& eId, const string& sId, const string& cId, int sem = 3);
    void drop();
    void display() const;
    void printSlip(const string& studentName, const string& courseTitle, int credits) const;

    string getEnrollmentId() const;
    string getStudentId() const;
    string getCourseId() const;
    string getStatus() const;
    string getEnrollmentDate() const;
    int getSemester() const;

    void setStatus(const string& s);
    void setEnrollmentDate(const string& d);
    void setSemester(int sem);
};

#endif
