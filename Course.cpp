#include "Course.h"
#include <iomanip>

Course::Course()
    : courseId(""), title(""), credits(3), maxSeats(10), enrolledCount(0), instructorId("F101") {
    enrolledStudentIds = new string[maxSeats];
}

Course::Course(string cId, string t, int cr, int seats, string instId)
    : courseId(cId), title(t), credits(cr), maxSeats(seats), enrolledCount(0), instructorId(instId) {
    if (maxSeats <= 0) maxSeats = 10;
    enrolledStudentIds = new string[maxSeats];
}

Course::Course(const Course& other)
    : courseId(other.courseId), title(other.title), credits(other.credits),
      maxSeats(other.maxSeats), enrolledCount(other.enrolledCount), instructorId(other.instructorId) {
    enrolledStudentIds = new string[maxSeats];
    for (int i = 0; i < enrolledCount; ++i) {
        enrolledStudentIds[i] = other.enrolledStudentIds[i];
    }
}

Course& Course::operator=(const Course& other) {
    if (this != &other) {
        delete[] enrolledStudentIds;

        courseId = other.courseId;
        title = other.title;
        credits = other.credits;
        maxSeats = other.maxSeats;
        enrolledCount = other.enrolledCount;
        instructorId = other.instructorId;

        enrolledStudentIds = new string[maxSeats];
        for (int i = 0; i < enrolledCount; ++i) {
            enrolledStudentIds[i] = other.enrolledStudentIds[i];
        }
    }
    return *this;
}

Course::~Course() {
    delete[] enrolledStudentIds;
    enrolledStudentIds = nullptr;
}

void Course::display() const {
    string seatInfo = to_string(enrolledCount) + "/" + to_string(maxSeats);
    cout << left << setw(12) << courseId
         << setw(32) << title
         << setw(10) << credits
         << setw(14) << seatInfo
         << setw(12) << (hasSeat() ? "AVAILABLE" : "FULL")
         << setw(14) << instructorId;
}

bool Course::hasSeat() const {
    return enrolledCount < maxSeats;
}

bool Course::enrollStudent(const string& sId) {
    if (!hasSeat()) return false;
    if (isStudentEnrolled(sId)) return false;

    enrolledStudentIds[enrolledCount] = sId;
    enrolledCount++;
    return true;
}

bool Course::dropStudent(const string& sId) {
    int foundIndex = -1;
    for (int i = 0; i < enrolledCount; ++i) {
        if (enrolledStudentIds[i] == sId) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) return false;

    for (int i = foundIndex; i < enrolledCount - 1; ++i) {
        enrolledStudentIds[i] = enrolledStudentIds[i + 1];
    }
    enrolledCount--;
    return true;
}

bool Course::isStudentEnrolled(const string& sId) const {
    for (int i = 0; i < enrolledCount; ++i) {
        if (enrolledStudentIds[i] == sId) {
            return true;
        }
    }
    return false;
}

string Course::getCourseId() const {
    return courseId;
}

string Course::getTitle() const {
    return title;
}

int Course::getCredits() const {
    return credits;
}

int Course::getMaxSeats() const {
    return maxSeats;
}

int Course::getEnrolledCount() const {
    return enrolledCount;
}

int Course::getAvailableSeats() const {
    return maxSeats - enrolledCount;
}

string Course::getInstructorId() const {
    return instructorId;
}

string Course::getEnrolledStudent(int index) const {
    if (index >= 0 && index < enrolledCount) {
        return enrolledStudentIds[index];
    }
    return "";
}

void Course::setTitle(const string& t) {
    title = t;
}

void Course::setCredits(int cr) {
    credits = cr;
}

void Course::setMaxSeats(int seats) {
    if (seats >= enrolledCount) {
        string* newArray = new string[seats];
        for (int i = 0; i < enrolledCount; ++i) {
            newArray[i] = enrolledStudentIds[i];
        }
        delete[] enrolledStudentIds;
        enrolledStudentIds = newArray;
        maxSeats = seats;
    }
}

void Course::setInstructorId(const string& instId) {
    instructorId = instId;
}
