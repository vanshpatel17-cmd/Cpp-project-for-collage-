#ifndef EDUCATIONSYSTEM_H
#define EDUCATIONSYSTEM_H

#include <string>
#include "Student.h"
#include "Course.h"
#include "Faculty.h"
#include "Enrollment.h"
#include "FileManager.h"
#include "Exceptions.h"

using namespace std;

class EducationSystem {
private:
    Student* students;
    int studentCount;
    int studentCapacity;

    Course* courses;
    int courseCount;
    int courseCapacity;

    Enrollment* enrollments;
    int enrollmentCount;
    int enrollmentCapacity;

    Faculty* facultyList;
    int facultyCount;
    int facultyCapacity;

    FileManager fileManager;
    string dataDirectory;

    void resizeStudents();
    void resizeCourses();
    void resizeEnrollments();
    void resizeFaculty();

public:
    EducationSystem(string dataDir = "Data/");
    EducationSystem(const EducationSystem& other);
    EducationSystem& operator=(const EducationSystem& other);
    ~EducationSystem();

    void initialize();
    void seedSampleData();

    void addStudent(const Student& s);
    void addCourse(const Course& c);
    void addFaculty(const Faculty& f);

    Student* findStudent(const string& sId);
    Course* findCourse(const string& cId);
    Faculty* findFaculty(const string& fId);
    Enrollment* findEnrollment(const string& eId);

    bool enrollStudent(const string& sId, const string& cId);
    bool dropStudent(const string& sId, const string& cId);

    void displayAllStudents() const;
    void displayAllCourses() const;
    void displayAllFaculty() const;
    void displayAllEnrollments() const;

    void displayPersonPolymorphic(const Person* personPtr) const;

    void addRecordMenu();
    void displayRecordsMenu();
    void searchRecordMenu();
    void updateRecordMenu();
    void deleteRecordMenu();
    void mainTransaction();
    void dropTransaction();
    void generateReports();
    void saveLoadMenu();

    bool saveAllData();
    bool loadAllData();

    int getStudentCount() const;
    int getCourseCount() const;
    int getEnrollmentCount() const;
    int getFacultyCount() const;
};

#endif
