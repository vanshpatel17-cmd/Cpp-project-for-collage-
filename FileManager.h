#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <vector>
#include "Student.h"
#include "Course.h"
#include "Faculty.h"
#include "Enrollment.h"

using namespace std;

class FileManager {
private:
    string dataDir;
    string studentsFile;
    string coursesFile;
    string facultyFile;
    string enrollmentsFile;

    vector<string> split(const string& str, char delimiter);
    string trim(const string& str);

public:
    FileManager(string dir = "Data/");
    ~FileManager();

    void ensureDirectory();

    bool saveStudents(const Student* students, int count);
    bool loadStudents(Student*& students, int& count, int& capacity);

    bool saveCourses(const Course* courses, int count);
    bool loadCourses(Course*& courses, int& count, int& capacity);

    bool saveFaculty(const Faculty* facultyList, int count);
    bool loadFaculty(Faculty*& facultyList, int& count, int& capacity);

    bool saveEnrollments(const Enrollment* enrollments, int count);
    bool loadEnrollments(Enrollment*& enrollments, int& count, int& capacity);
};

#endif
