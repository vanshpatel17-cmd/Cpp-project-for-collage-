#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>

using namespace std;

class Course {
private:
    string courseId;
    string title;
    int credits;
    int maxSeats;
    int enrolledCount;
    string instructorId;
    string* enrolledStudentIds;

public:
    Course();
    Course(string cId, string t, int cr, int seats, string instId = "F101");
    Course(const Course& other);
    Course& operator=(const Course& other);
    ~Course();

    void display() const;
    bool hasSeat() const;
    bool enrollStudent(const string& sId);
    bool dropStudent(const string& sId);
    bool isStudentEnrolled(const string& sId) const;

    string getCourseId() const;
    string getTitle() const;
    int getCredits() const;
    int getMaxSeats() const;
    int getEnrolledCount() const;
    int getAvailableSeats() const;
    string getInstructorId() const;
    string getEnrolledStudent(int index) const;

    void setTitle(const string& t);
    void setCredits(int cr);
    void setMaxSeats(int seats);
    void setInstructorId(const string& instId);
};

#endif
