#include "FileManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <direct.h>

FileManager::FileManager(string dir) : dataDir(dir) {
    if (!dataDir.empty() && dataDir.back() != '/' && dataDir.back() != '\\') {
        dataDir += "/";
    }
    studentsFile = dataDir + "students.txt";
    coursesFile = dataDir + "courses.txt";
    facultyFile = dataDir + "faculty.txt";
    enrollmentsFile = dataDir + "enrollments.txt";
}

FileManager::~FileManager() {}

void FileManager::ensureDirectory() {
    _mkdir(dataDir.c_str());
}

string FileManager::trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}

vector<string> FileManager::split(const string& str, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(str);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(trim(token));
    }
    return tokens;
}

bool FileManager::saveStudents(const Student* students, int count) {
    ensureDirectory();
    ofstream outFile(studentsFile);
    if (!outFile.is_open()) return false;

    for (int i = 0; i < count; ++i) {
        outFile << students[i].getStudentId() << "|"
                << students[i].getName() << "|"
                << students[i].getEmail() << "|"
                << students[i].getContactNumber() << "|"
                << students[i].getSemester() << "|"
                << students[i].getDepartment() << "|"
                << students[i].getEnrolledCredits() << "|"
                << students[i].getMaxCredits() << "\n";
    }
    outFile.close();
    return true;
}

bool FileManager::loadStudents(Student*& students, int& count, int& capacity) {
    ifstream inFile(studentsFile);
    if (!inFile.is_open()) return false;

    string line;
    count = 0;
    while (getline(inFile, line)) {
        line = trim(line);
        if (line.empty()) continue;

        vector<string> parts = split(line, '|');
        if (parts.size() >= 8) {
            if (count >= capacity) {
                int newCap = capacity * 2;
                Student* newArr = new Student[newCap];
                for (int i = 0; i < count; ++i) {
                    newArr[i] = students[i];
                }
                delete[] students;
                students = newArr;
                capacity = newCap;
            }

            Student s(parts[0], parts[1], parts[2], parts[3], stoi(parts[4]), parts[5], stoi(parts[7]));
            s.setEnrolledCredits(stoi(parts[6]));
            students[count++] = s;
        }
    }
    inFile.close();
    return true;
}

bool FileManager::saveCourses(const Course* courses, int count) {
    ensureDirectory();
    ofstream outFile(coursesFile);
    if (!outFile.is_open()) return false;

    for (int i = 0; i < count; ++i) {
        outFile << courses[i].getCourseId() << "|"
                << courses[i].getTitle() << "|"
                << courses[i].getCredits() << "|"
                << courses[i].getMaxSeats() << "|"
                << courses[i].getInstructorId() << "|";

        int enr = courses[i].getEnrolledCount();
        for (int j = 0; j < enr; ++j) {
            outFile << courses[i].getEnrolledStudent(j);
            if (j < enr - 1) outFile << ",";
        }
        outFile << "\n";
    }
    outFile.close();
    return true;
}

bool FileManager::loadCourses(Course*& courses, int& count, int& capacity) {
    ifstream inFile(coursesFile);
    if (!inFile.is_open()) return false;

    string line;
    count = 0;
    while (getline(inFile, line)) {
        line = trim(line);
        if (line.empty()) continue;

        vector<string> parts = split(line, '|');
        if (parts.size() >= 5) {
            if (count >= capacity) {
                int newCap = capacity * 2;
                Course* newArr = new Course[newCap];
                for (int i = 0; i < count; ++i) {
                    newArr[i] = courses[i];
                }
                delete[] courses;
                courses = newArr;
                capacity = newCap;
            }

            Course c(parts[0], parts[1], stoi(parts[2]), stoi(parts[3]), parts[4]);
            if (parts.size() >= 6 && !parts[5].empty()) {
                vector<string> enrolled = split(parts[5], ',');
                for (const auto& sid : enrolled) {
                    if (!sid.empty()) {
                        c.enrollStudent(sid);
                    }
                }
            }
            courses[count++] = c;
        }
    }
    inFile.close();
    return true;
}

bool FileManager::saveFaculty(const Faculty* facultyList, int count) {
    ensureDirectory();
    ofstream outFile(facultyFile);
    if (!outFile.is_open()) return false;

    for (int i = 0; i < count; ++i) {
        outFile << facultyList[i].getFacultyId() << "|"
                << facultyList[i].getName() << "|"
                << facultyList[i].getEmail() << "|"
                << facultyList[i].getContactNumber() << "|"
                << facultyList[i].getDepartment() << "|"
                << facultyList[i].getDesignation() << "\n";
    }
    outFile.close();
    return true;
}

bool FileManager::loadFaculty(Faculty*& facultyList, int& count, int& capacity) {
    ifstream inFile(facultyFile);
    if (!inFile.is_open()) return false;

    string line;
    count = 0;
    while (getline(inFile, line)) {
        line = trim(line);
        if (line.empty()) continue;

        vector<string> parts = split(line, '|');
        if (parts.size() >= 6) {
            if (count >= capacity) {
                int newCap = capacity * 2;
                Faculty* newArr = new Faculty[newCap];
                for (int i = 0; i < count; ++i) {
                    newArr[i] = facultyList[i];
                }
                delete[] facultyList;
                facultyList = newArr;
                capacity = newCap;
            }

            Faculty f(parts[0], parts[1], parts[2], parts[3], parts[4], parts[5]);
            facultyList[count++] = f;
        }
    }
    inFile.close();
    return true;
}

bool FileManager::saveEnrollments(const Enrollment* enrollments, int count) {
    ensureDirectory();
    ofstream outFile(enrollmentsFile);
    if (!outFile.is_open()) return false;

    for (int i = 0; i < count; ++i) {
        outFile << enrollments[i].getEnrollmentId() << "|"
                << enrollments[i].getStudentId() << "|"
                << enrollments[i].getCourseId() << "|"
                << enrollments[i].getStatus() << "|"
                << enrollments[i].getEnrollmentDate() << "|"
                << enrollments[i].getSemester() << "\n";
    }
    outFile.close();
    return true;
}

bool FileManager::loadEnrollments(Enrollment*& enrollments, int& count, int& capacity) {
    ifstream inFile(enrollmentsFile);
    if (!inFile.is_open()) return false;

    string line;
    count = 0;
    while (getline(inFile, line)) {
        line = trim(line);
        if (line.empty()) continue;

        vector<string> parts = split(line, '|');
        if (parts.size() >= 6) {
            if (count >= capacity) {
                int newCap = capacity * 2;
                Enrollment* newArr = new Enrollment[newCap];
                for (int i = 0; i < count; ++i) {
                    newArr[i] = enrollments[i];
                }
                delete[] enrollments;
                enrollments = newArr;
                capacity = newCap;
            }

            Enrollment e(parts[0], parts[1], parts[2], parts[3], parts[4], stoi(parts[5]));
            enrollments[count++] = e;
        }
    }
    inFile.close();
    return true;
}
