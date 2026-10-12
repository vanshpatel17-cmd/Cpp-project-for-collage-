#include "EducationSystem.h"
#include <iostream>
#include <iomanip>
#include <fstream>

EducationSystem::EducationSystem(string dataDir)
    : studentCount(0), studentCapacity(10),
      courseCount(0), courseCapacity(10),
      enrollmentCount(0), enrollmentCapacity(20),
      facultyCount(0), facultyCapacity(10),
      fileManager(dataDir), dataDirectory(dataDir) {
    students = new Student[studentCapacity];
    courses = new Course[courseCapacity];
    enrollments = new Enrollment[enrollmentCapacity];
    facultyList = new Faculty[facultyCapacity];
}

EducationSystem::EducationSystem(const EducationSystem& other)
    : studentCount(other.studentCount), studentCapacity(other.studentCapacity),
      courseCount(other.courseCount), courseCapacity(other.courseCapacity),
      enrollmentCount(other.enrollmentCount), enrollmentCapacity(other.enrollmentCapacity),
      facultyCount(other.facultyCount), facultyCapacity(other.facultyCapacity),
      fileManager(other.fileManager), dataDirectory(other.dataDirectory) {
    students = new Student[studentCapacity];
    for (int i = 0; i < studentCount; ++i) students[i] = other.students[i];

    courses = new Course[courseCapacity];
    for (int i = 0; i < courseCount; ++i) courses[i] = other.courses[i];

    enrollments = new Enrollment[enrollmentCapacity];
    for (int i = 0; i < enrollmentCount; ++i) enrollments[i] = other.enrollments[i];

    facultyList = new Faculty[facultyCapacity];
    for (int i = 0; i < facultyCount; ++i) facultyList[i] = other.facultyList[i];
}

EducationSystem& EducationSystem::operator=(const EducationSystem& other) {
    if (this != &other) {
        delete[] students;
        delete[] courses;
        delete[] enrollments;
        delete[] facultyList;

        studentCount = other.studentCount;
        studentCapacity = other.studentCapacity;
        courseCount = other.courseCount;
        courseCapacity = other.courseCapacity;
        enrollmentCount = other.enrollmentCount;
        enrollmentCapacity = other.enrollmentCapacity;
        facultyCount = other.facultyCount;
        facultyCapacity = other.facultyCapacity;
        fileManager = other.fileManager;
        dataDirectory = other.dataDirectory;

        students = new Student[studentCapacity];
        for (int i = 0; i < studentCount; ++i) students[i] = other.students[i];

        courses = new Course[courseCapacity];
        for (int i = 0; i < courseCount; ++i) courses[i] = other.courses[i];

        enrollments = new Enrollment[enrollmentCapacity];
        for (int i = 0; i < enrollmentCount; ++i) enrollments[i] = other.enrollments[i];

        facultyList = new Faculty[facultyCapacity];
        for (int i = 0; i < facultyCount; ++i) facultyList[i] = other.facultyList[i];
    }
    return *this;
}

EducationSystem::~EducationSystem() {
    delete[] students;
    delete[] courses;
    delete[] enrollments;
    delete[] facultyList;
}

void EducationSystem::resizeStudents() {
    studentCapacity *= 2;
    Student* temp = new Student[studentCapacity];
    for (int i = 0; i < studentCount; ++i) temp[i] = students[i];
    delete[] students;
    students = temp;
}

void EducationSystem::resizeCourses() {
    courseCapacity *= 2;
    Course* temp = new Course[courseCapacity];
    for (int i = 0; i < courseCount; ++i) temp[i] = courses[i];
    delete[] courses;
    courses = temp;
}

void EducationSystem::resizeEnrollments() {
    enrollmentCapacity *= 2;
    Enrollment* temp = new Enrollment[enrollmentCapacity];
    for (int i = 0; i < enrollmentCount; ++i) temp[i] = enrollments[i];
    delete[] enrollments;
    enrollments = temp;
}

void EducationSystem::resizeFaculty() {
    facultyCapacity *= 2;
    Faculty* temp = new Faculty[facultyCapacity];
    for (int i = 0; i < facultyCount; ++i) temp[i] = facultyList[i];
    delete[] facultyList;
    facultyList = temp;
}

void EducationSystem::initialize() {
    fileManager.ensureDirectory();
    if (!loadAllData() || studentCount == 0 || courseCount == 0) {
        seedSampleData();
        saveAllData();
    }
}

void EducationSystem::seedSampleData() {
    studentCount = 0;
    courseCount = 0;
    enrollmentCount = 0;
    facultyCount = 0;

    Student s1("S101", "Vansh Patel", "vansh.p@indusuni.ac.in", "9876543210", 3, "Cyber Security", 24);
    Student s2("S102", "Priya Sharma", "priya.s@indusuni.ac.in", "9812345678", 3, "CSE", 24);
    Student s3("S103", "Rahul Mehta", "rahul.m@indusuni.ac.in", "9823456789", 3, "IT", 24);
    Student s4("S104", "Neha Patel", "neha.p@indusuni.ac.in", "9834567890", 3, "CSE", 24);

    addStudent(s1);
    addStudent(s2);
    addStudent(s3);
    addStudent(s4);

    Faculty f1("F101", "Dr. Rajesh Varma", "rajesh.v@indusuni.ac.in", "9845678901", "CSE", "Professor");
    Faculty f2("F102", "Prof. Sneha Joshi", "sneha.j@indusuni.ac.in", "9856789012", "Cyber Security", "Associate Professor");
    Faculty f3("F103", "Prof. Amit Dave", "amit.d@indusuni.ac.in", "9867890123", "IT", "Assistant Professor");

    addFaculty(f1);
    addFaculty(f2);
    addFaculty(f3);

    Course c1("CS301", "Object Oriented Programming C++", 4, 30, "F101");
    Course c2("CS302", "Data Structures & Algorithms", 4, 25, "F102");
    Course c3("CS303", "Database Management Systems", 3, 20, "F101");
    Course c4("CS304", "Computer Networks", 3, 20, "F103");
    Course c5("CS305", "Cyber Security Fundamentals", 4, 15, "F102");

    addCourse(c1);
    addCourse(c2);
    addCourse(c3);
    addCourse(c4);
    addCourse(c5);

    enrollStudent("S101", "CS301");
    enrollStudent("S101", "CS305");
    enrollStudent("S102", "CS301");
    enrollStudent("S103", "CS302");
}

void EducationSystem::addStudent(const Student& s) {
    if (studentCount >= studentCapacity) resizeStudents();
    students[studentCount++] = s;
}

void EducationSystem::addCourse(const Course& c) {
    if (courseCount >= courseCapacity) resizeCourses();
    courses[courseCount++] = c;
}

void EducationSystem::addFaculty(const Faculty& f) {
    if (facultyCount >= facultyCapacity) resizeFaculty();
    facultyList[facultyCount++] = f;
}

Student* EducationSystem::findStudent(const string& sId) {
    for (int i = 0; i < studentCount; ++i) {
        if (students[i].getStudentId() == sId) return &students[i];
    }
    return nullptr;
}

Course* EducationSystem::findCourse(const string& cId) {
    for (int i = 0; i < courseCount; ++i) {
        if (courses[i].getCourseId() == cId) return &courses[i];
    }
    return nullptr;
}

Faculty* EducationSystem::findFaculty(const string& fId) {
    for (int i = 0; i < facultyCount; ++i) {
        if (facultyList[i].getFacultyId() == fId) return &facultyList[i];
    }
    return nullptr;
}

Enrollment* EducationSystem::findEnrollment(const string& eId) {
    for (int i = 0; i < enrollmentCount; ++i) {
        if (enrollments[i].getEnrollmentId() == eId) return &enrollments[i];
    }
    return nullptr;
}

bool EducationSystem::enrollStudent(const string& sId, const string& cId) {
    Student* s = findStudent(sId);
    if (!s) throw StudentNotFoundException("Student ID " + sId + " does not exist!");

    Course* c = findCourse(cId);
    if (!c) throw CourseNotFoundException("Course ID " + cId + " does not exist!");

    if (!c->hasSeat()) {
        throw CourseFullException("Course " + cId + " is full! No seats available.");
    }

    if (c->isStudentEnrolled(sId)) {
        throw AlreadyEnrolledException("Student " + sId + " is already enrolled in " + cId + "!");
    }

    if (!s->canTakeCredits(c->getCredits())) {
        throw CreditLimitExceededException("Credit limit exceeded! Student cannot register for " + to_string(c->getCredits()) + " more credits.");
    }

    c->enrollStudent(sId);
    s->addCredits(c->getCredits());

    string eId = "E" + to_string(1001 + enrollmentCount);
    Enrollment enr(eId, sId, cId, "ENROLLED", "2026-10-12", s->getSemester());

    if (enrollmentCount >= enrollmentCapacity) resizeEnrollments();
    enrollments[enrollmentCount++] = enr;

    return true;
}

bool EducationSystem::dropStudent(const string& sId, const string& cId) {
    Student* s = findStudent(sId);
    if (!s) throw StudentNotFoundException("Student ID " + sId + " not found!");

    Course* c = findCourse(cId);
    if (!c) throw CourseNotFoundException("Course ID " + cId + " not found!");

    if (!c->isStudentEnrolled(sId)) {
        throw NotEnrolledException("Student " + sId + " is not currently enrolled in " + cId + "!");
    }

    c->dropStudent(sId);
    s->removeCredits(c->getCredits());

    for (int i = 0; i < enrollmentCount; ++i) {
        if (enrollments[i].getStudentId() == sId && enrollments[i].getCourseId() == cId && enrollments[i].getStatus() == "ENROLLED") {
            enrollments[i].drop();
            break;
        }
    }

    return true;
}

void EducationSystem::displayAllStudents() const {
    cout << "\n-------------------------------- STUDENT RECORDS --------------------------------\n";
    cout << left << setw(14) << "STUDENT ID"
         << setw(20) << "NAME"
         << setw(8)  << "SEM"
         << setw(16) << "DEPARTMENT"
         << setw(14) << "CREDITS"
         << setw(16) << "CONTACT" << "\n";
    cout << "---------------------------------------------------------------------------------\n";
    for (int i = 0; i < studentCount; ++i) {
        students[i].display();
        cout << "\n";
    }
    cout << "---------------------------------------------------------------------------------\n";
    cout << "Total Students: " << studentCount << "\n";
}

void EducationSystem::displayAllCourses() const {
    cout << "\n-------------------------------- COURSE CATALOG --------------------------------\n";
    cout << left << setw(12) << "COURSE ID"
         << setw(32) << "TITLE"
         << setw(10) << "CREDITS"
         << setw(14) << "SEATS"
         << setw(12) << "STATUS"
         << setw(14) << "FACULTY ID" << "\n";
    cout << "--------------------------------------------------------------------------------\n";
    for (int i = 0; i < courseCount; ++i) {
        courses[i].display();
        cout << "\n";
    }
    cout << "--------------------------------------------------------------------------------\n";
    cout << "Total Courses: " << courseCount << "\n";
}

void EducationSystem::displayAllFaculty() const {
    cout << "\n-------------------------------- FACULTY RECORDS --------------------------------\n";
    cout << left << setw(14) << "FACULTY ID"
         << setw(22) << "NAME"
         << setw(18) << "DEPARTMENT"
         << setw(22) << "DESIGNATION"
         << setw(16) << "CONTACT" << "\n";
    cout << "---------------------------------------------------------------------------------\n";
    for (int i = 0; i < facultyCount; ++i) {
        facultyList[i].display();
        cout << "\n";
    }
    cout << "---------------------------------------------------------------------------------\n";
    cout << "Total Faculty: " << facultyCount << "\n";
}

void EducationSystem::displayAllEnrollments() const {
    cout << "\n------------------------------ ENROLLMENT RECORDS ------------------------------\n";
    cout << left << setw(14) << "ENROLL ID"
         << setw(16) << "STUDENT ID"
         << setw(14) << "COURSE ID"
         << setw(14) << "STATUS"
         << setw(14) << "DATE"
         << setw(8)  << "SEM" << "\n";
    cout << "--------------------------------------------------------------------------------\n";
    for (int i = 0; i < enrollmentCount; ++i) {
        enrollments[i].display();
        cout << "\n";
    }
    cout << "--------------------------------------------------------------------------------\n";
    cout << "Total Enrollments: " << enrollmentCount << "\n";
}

void EducationSystem::displayPersonPolymorphic(const Person* personPtr) const {
    if (personPtr) {
        cout << "Role: [" << left << setw(10) << personPtr->getRole() << "] Details: ";
        personPtr->display();
        cout << "\n";
    }
}

void EducationSystem::addRecordMenu() {
    int opt = 0;
    while (true) {
        cout << "\n======================== ADD RECORD SUBMENU ========================\n";
        cout << "  1. Add New Student\n";
        cout << "  2. Add New Course\n";
        cout << "  3. Add New Faculty\n";
        cout << "  4. Back to Main Menu\n";
        cout << "====================================================================\n";
        cout << "Enter your choice (1-4): ";
        if (!(cin >> opt)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        cin.ignore(1000, '\n');

        if (opt == 1) {
            string sId, name, email, contact, dept;
            int sem, maxCr;
            cout << "Enter Student ID (e.g. S105): ";
            getline(cin, sId);
            if (findStudent(sId)) {
                cout << "Error: Student ID already exists!\n";
                continue;
            }
            cout << "Enter Student Name: ";
            getline(cin, name);
            cout << "Enter Email Address: ";
            getline(cin, email);
            cout << "Enter Contact Number: ";
            getline(cin, contact);
            cout << "Enter Semester (1-8): ";
            cin >> sem;
            cin.ignore(1000, '\n');
            cout << "Enter Department: ";
            getline(cin, dept);
            cout << "Enter Max Allowed Credits (default 24): ";
            cin >> maxCr;
            cin.ignore(1000, '\n');

            Student newS(sId, name, email, contact, sem, dept, maxCr);
            addStudent(newS);
            cout << "\nStudent record added successfully!\n";
        } else if (opt == 2) {
            string cId, title, instId;
            int credits, seats;
            cout << "Enter Course ID (e.g. CS306): ";
            getline(cin, cId);
            if (findCourse(cId)) {
                cout << "Error: Course ID already exists!\n";
                continue;
            }
            cout << "Enter Course Title: ";
            getline(cin, title);
            cout << "Enter Credits (1-5): ";
            cin >> credits;
            cout << "Enter Max Seat Capacity: ";
            cin >> seats;
            cin.ignore(1000, '\n');
            cout << "Enter Instructor Faculty ID (e.g. F101): ";
            getline(cin, instId);

            Course newC(cId, title, credits, seats, instId);
            addCourse(newC);
            cout << "\nCourse record added successfully!\n";
        } else if (opt == 3) {
            string fId, name, email, contact, dept, desig;
            cout << "Enter Faculty ID (e.g. F104): ";
            getline(cin, fId);
            if (findFaculty(fId)) {
                cout << "Error: Faculty ID already exists!\n";
                continue;
            }
            cout << "Enter Faculty Name: ";
            getline(cin, name);
            cout << "Enter Email Address: ";
            getline(cin, email);
            cout << "Enter Contact Number: ";
            getline(cin, contact);
            cout << "Enter Department: ";
            getline(cin, dept);
            cout << "Enter Designation: ";
            getline(cin, desig);

            Faculty newF(fId, name, email, contact, dept, desig);
            addFaculty(newF);
            cout << "\nFaculty record added successfully!\n";
        } else if (opt == 4) {
            break;
        } else {
            cout << "Invalid choice! Enter 1-4.\n";
        }
    }
}

void EducationSystem::displayRecordsMenu() {
    int opt = 0;
    while (true) {
        cout << "\n====================== DISPLAY RECORDS SUBMENU ======================\n";
        cout << "  1. Display All Students\n";
        cout << "  2. Display All Courses\n";
        cout << "  3. Display All Faculty\n";
        cout << "  4. Display All Enrollments\n";
        cout << "  5. Polymorphic Person Display (Runtime Polymorphism)\n";
        cout << "  6. Back to Main Menu\n";
        cout << "====================================================================\n";
        cout << "Enter your choice (1-6): ";
        if (!(cin >> opt)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        cin.ignore(1000, '\n');

        if (opt == 1) displayAllStudents();
        else if (opt == 2) displayAllCourses();
        else if (opt == 3) displayAllFaculty();
        else if (opt == 4) displayAllEnrollments();
        else if (opt == 5) {
            cout << "\n--- DEMONSTRATING RUNTIME POLYMORPHISM (Person* Base Pointer) ---\n";
            for (int i = 0; i < studentCount && i < 2; ++i) {
                const Person* p = &students[i];
                displayPersonPolymorphic(p);
            }
            for (int i = 0; i < facultyCount && i < 2; ++i) {
                const Person* p = &facultyList[i];
                displayPersonPolymorphic(p);
            }
            cout << "-----------------------------------------------------------------\n";
        } else if (opt == 6) break;
        else cout << "Invalid choice! Enter 1-6.\n";
    }
}

void EducationSystem::searchRecordMenu() {
    int opt = 0;
    while (true) {
        cout << "\n======================= SEARCH RECORD SUBMENU =======================\n";
        cout << "  1. Search Student by ID\n";
        cout << "  2. Search Course by Code\n";
        cout << "  3. Search Enrollment by ID\n";
        cout << "  4. Back to Main Menu\n";
        cout << "====================================================================\n";
        cout << "Enter your choice (1-4): ";
        if (!(cin >> opt)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        cin.ignore(1000, '\n');

        if (opt == 1) {
            string sId;
            cout << "Enter Student ID to search (e.g. S101): ";
            getline(cin, sId);
            Student* s = findStudent(sId);
            if (s) {
                cout << "\n[STUDENT FOUND]\n";
                cout << "---------------------------------------------------------------------------------\n";
                s->display();
                cout << "\n---------------------------------------------------------------------------------\n";
            } else {
                cout << "\nNo student record found for ID: " << sId << "\n";
            }
        } else if (opt == 2) {
            string cId;
            cout << "Enter Course Code to search (e.g. CS301): ";
            getline(cin, cId);
            Course* c = findCourse(cId);
            if (c) {
                cout << "\n[COURSE FOUND]\n";
                cout << "--------------------------------------------------------------------------------\n";
                c->display();
                cout << "\n--------------------------------------------------------------------------------\n";
                cout << "Enrolled Students (" << c->getEnrolledCount() << "/" << c->getMaxSeats() << "): ";
                for (int i = 0; i < c->getEnrolledCount(); ++i) {
                    cout << c->getEnrolledStudent(i) << (i < c->getEnrolledCount() - 1 ? ", " : "");
                }
                cout << "\n";
            } else {
                cout << "\nNo course record found for ID: " << cId << "\n";
            }
        } else if (opt == 3) {
            string eId;
            cout << "Enter Enrollment ID to search (e.g. E1001): ";
            getline(cin, eId);
            Enrollment* e = findEnrollment(eId);
            if (e) {
                cout << "\n[ENROLLMENT FOUND]\n";
                cout << "--------------------------------------------------------------------------------\n";
                e->display();
                cout << "\n--------------------------------------------------------------------------------\n";
            } else {
                cout << "\nNo enrollment record found for ID: " << eId << "\n";
            }
        } else if (opt == 4) break;
        else cout << "Invalid choice! Enter 1-4.\n";
    }
}

void EducationSystem::updateRecordMenu() {
    int opt = 0;
    while (true) {
        cout << "\n======================= UPDATE RECORD SUBMENU =======================\n";
        cout << "  1. Update Student Details\n";
        cout << "  2. Update Course Seats & Title\n";
        cout << "  3. Back to Main Menu\n";
        cout << "====================================================================\n";
        cout << "Enter your choice (1-3): ";
        if (!(cin >> opt)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        cin.ignore(1000, '\n');

        if (opt == 1) {
            string sId;
            cout << "Enter Student ID to update: ";
            getline(cin, sId);
            Student* s = findStudent(sId);
            if (!s) {
                cout << "Student not found!\n";
                continue;
            }
            string name, email, contact, dept;
            int sem;
            cout << "Current Name: " << s->getName() << ". Enter New Name (or Enter to keep): ";
            getline(cin, name);
            cout << "Current Email: " << s->getEmail() << ". Enter New Email (or Enter to keep): ";
            getline(cin, email);
            cout << "Current Contact: " << s->getContactNumber() << ". Enter New Contact: ";
            getline(cin, contact);
            cout << "Current Semester: " << s->getSemester() << ". Enter New Semester (0 to keep): ";
            cin >> sem;
            cin.ignore(1000, '\n');
            cout << "Current Dept: " << s->getDepartment() << ". Enter New Dept: ";
            getline(cin, dept);

            s->update(name, email, contact, sem, dept);
            cout << "\nStudent record updated successfully!\n";
        } else if (opt == 2) {
            string cId;
            cout << "Enter Course ID to update: ";
            getline(cin, cId);
            Course* c = findCourse(cId);
            if (!c) {
                cout << "Course not found!\n";
                continue;
            }
            string title;
            int seats, cred;
            cout << "Current Title: " << c->getTitle() << ". Enter New Title (or Enter to keep): ";
            getline(cin, title);
            if (!title.empty()) c->setTitle(title);

            cout << "Current Credits: " << c->getCredits() << ". Enter New Credits (0 to keep): ";
            cin >> cred;
            if (cred > 0) c->setCredits(cred);

            cout << "Current Max Seats: " << c->getMaxSeats() << ". Enter New Max Seats (0 to keep): ";
            cin >> seats;
            cin.ignore(1000, '\n');
            if (seats > 0) c->setMaxSeats(seats);

            cout << "\nCourse record updated successfully!\n";
        } else if (opt == 3) break;
        else cout << "Invalid choice! Enter 1-3.\n";
    }
}

void EducationSystem::deleteRecordMenu() {
    int opt = 0;
    while (true) {
        cout << "\n======================= DELETE RECORD SUBMENU =======================\n";
        cout << "  1. Delete Student Record\n";
        cout << "  2. Delete Course Record\n";
        cout << "  3. Back to Main Menu\n";
        cout << "====================================================================\n";
        cout << "Enter your choice (1-3): ";
        if (!(cin >> opt)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        cin.ignore(1000, '\n');

        if (opt == 1) {
            string sId;
            cout << "Enter Student ID to delete: ";
            getline(cin, sId);
            int idx = -1;
            for (int i = 0; i < studentCount; ++i) {
                if (students[i].getStudentId() == sId) {
                    idx = i;
                    break;
                }
            }
            if (idx == -1) {
                cout << "Student not found!\n";
                continue;
            }
            for (int i = idx; i < studentCount - 1; ++i) {
                students[i] = students[i + 1];
            }
            studentCount--;
            cout << "\nStudent record deleted successfully!\n";
        } else if (opt == 2) {
            string cId;
            cout << "Enter Course ID to delete: ";
            getline(cin, cId);
            int idx = -1;
            for (int i = 0; i < courseCount; ++i) {
                if (courses[i].getCourseId() == cId) {
                    idx = i;
                    break;
                }
            }
            if (idx == -1) {
                cout << "Course not found!\n";
                continue;
            }
            for (int i = idx; i < courseCount - 1; ++i) {
                courses[i] = courses[i + 1];
            }
            courseCount--;
            cout << "\nCourse record deleted successfully!\n";
        } else if (opt == 3) break;
        else cout << "Invalid choice! Enter 1-3.\n";
    }
}

void EducationSystem::mainTransaction() {
    cout << "\n============================================================\n";
    cout << "      MAIN TRANSACTION: COURSE ENROLLMENT / REGISTRATION    \n";
    cout << "============================================================\n";

    displayAllCourses();

    string sId, cId;
    cout << "\nEnter Student ID (e.g. S101): ";
    getline(cin, sId);

    Student* s = findStudent(sId);
    if (!s) {
        cout << "Error: Student ID not found! Operation aborted.\n";
        return;
    }

    Person* personVerifier = new Student(*s);
    cout << "\n[POLYMORPHIC VERIFICATION]\n";
    displayPersonPolymorphic(personVerifier);

    cout << "\nEnter Course Code to Register (e.g. CS302): ";
    getline(cin, cId);

    Course* c = findCourse(cId);
    if (!c) {
        cout << "Error: Course ID not found! Operation aborted.\n";
        delete personVerifier;
        return;
    }

    try {
        bool success = enrollStudent(sId, cId);
        if (success) {
            Enrollment* latestEnr = &enrollments[enrollmentCount - 1];
            latestEnr->printSlip(s->getName(), c->getTitle(), c->getCredits());
        }
    } catch (const SystemException& ex) {
        cout << "\n[REGISTRATION FAILED] " << ex.what() << "\n";
    }

    delete personVerifier;
}

void EducationSystem::dropTransaction() {
    cout << "\n============================================================\n";
    cout << "         TRANSACTION 2: COURSE WITHDRAWAL / DROP            \n";
    cout << "============================================================\n";

    string sId, cId;
    cout << "Enter Student ID: ";
    getline(cin, sId);
    cout << "Enter Course Code to Drop: ";
    getline(cin, cId);

    try {
        bool success = dropStudent(sId, cId);
        if (success) {
            cout << "\n============================================================\n";
            cout << "  SUCCESS: Course " << cId << " dropped successfully for Student " << sId << "!\n";
            cout << "  Seat released back to course capacity.\n";
            cout << "============================================================\n\n";
        }
    } catch (const SystemException& ex) {
        cout << "\n[DROP FAILED] " << ex.what() << "\n";
    }
}

void EducationSystem::generateReports() {
    cout << "\n================================================================================\n";
    cout << "                ACADEMIC PERFORMANCE & REGISTRATION REPORT                      \n";
    cout << "               Indus Institute of Technology & Engineering                      \n";
    cout << "================================================================================\n";

    cout << "\n[1. COURSE OCCUPANCY & UTILIZATION MATRIX]\n";
    cout << left << setw(12) << "COURSE ID"
         << setw(32) << "TITLE"
         << setw(10) << "CREDITS"
         << setw(14) << "OCCUPANCY"
         << setw(14) << "UTILIZATION"
         << setw(12) << "STATUS" << "\n";
    cout << "--------------------------------------------------------------------------------\n";

    int totalCapacity = 0;
    int totalEnrolled = 0;
    for (int i = 0; i < courseCount; ++i) {
        int cap = courses[i].getMaxSeats();
        int enr = courses[i].getEnrolledCount();
        totalCapacity += cap;
        totalEnrolled += enr;
        double pct = (cap > 0) ? (static_cast<double>(enr) / cap * 100.0) : 0.0;

        stringstream ss;
        ss << fixed << setprecision(1) << pct << "%";

        cout << left << setw(12) << courses[i].getCourseId()
             << setw(32) << courses[i].getTitle()
             << setw(10) << courses[i].getCredits()
             << setw(14) << (to_string(enr) + "/" + to_string(cap))
             << setw(14) << ss.str()
             << setw(12) << (courses[i].hasSeat() ? "AVAILABLE" : "FULL") << "\n";
    }
    cout << "--------------------------------------------------------------------------------\n";
    double overallPct = (totalCapacity > 0) ? (static_cast<double>(totalEnrolled) / totalCapacity * 100.0) : 0.0;
    cout << "Total Seats Across Catalog: " << totalCapacity
         << " | Total Registrations: " << totalEnrolled
         << " | Overall Occupancy: " << fixed << setprecision(1) << overallPct << "%\n";

    cout << "\n[2. STUDENT CREDIT LOAD SUMMARY]\n";
    cout << left << setw(14) << "STUDENT ID"
         << setw(22) << "STUDENT NAME"
         << setw(16) << "CREDIT LOAD"
         << setw(16) << "STATUS" << "\n";
    cout << "--------------------------------------------------------------------------------\n";
    for (int i = 0; i < studentCount; ++i) {
        string status = (students[i].getEnrolledCredits() >= 12) ? "FULL-TIME" : "PART-TIME";
        cout << left << setw(14) << students[i].getStudentId()
             << setw(22) << students[i].getName()
             << setw(16) << (to_string(students[i].getEnrolledCredits()) + " Credits")
             << setw(16) << status << "\n";
    }
    cout << "--------------------------------------------------------------------------------\n\n";
}

void EducationSystem::saveLoadMenu() {
    int opt = 0;
    while (true) {
        cout << "\n======================= SAVE / LOAD DATA SUBMENU ======================\n";
        cout << "  1. Save All Records to Disk (Data/)\n";
        cout << "  2. Reload All Records from Disk (Data/)\n";
        cout << "  3. Seed Fresh Sample Data\n";
        cout << "  4. Back to Main Menu\n";
        cout << "=======================================================================\n";
        cout << "Enter your choice (1-4): ";
        if (!(cin >> opt)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        cin.ignore(1000, '\n');

        if (opt == 1) {
            if (saveAllData()) {
                cout << "\nAll records saved successfully to " << dataDirectory << "\n";
            } else {
                cout << "\nError saving records to disk!\n";
            }
        } else if (opt == 2) {
            if (loadAllData()) {
                cout << "\nAll records reloaded successfully from " << dataDirectory << "\n";
            } else {
                cout << "\nError reloading records from disk!\n";
            }
        } else if (opt == 3) {
            seedSampleData();
            saveAllData();
            cout << "\nFresh sample records seeded and saved to disk!\n";
        } else if (opt == 4) break;
        else cout << "Invalid choice! Enter 1-4.\n";
    }
}

bool EducationSystem::saveAllData() {
    bool okS = fileManager.saveStudents(students, studentCount);
    bool okC = fileManager.saveCourses(courses, courseCount);
    bool okF = fileManager.saveFaculty(facultyList, facultyCount);
    bool okE = fileManager.saveEnrollments(enrollments, enrollmentCount);
    return okS && okC && okF && okE;
}

bool EducationSystem::loadAllData() {
    bool okS = fileManager.loadStudents(students, studentCount, studentCapacity);
    bool okC = fileManager.loadCourses(courses, courseCount, courseCapacity);
    bool okF = fileManager.loadFaculty(facultyList, facultyCount, facultyCapacity);
    bool okE = fileManager.loadEnrollments(enrollments, enrollmentCount, enrollmentCapacity);
    return okS && okC && okF && okE;
}

int EducationSystem::getStudentCount() const { return studentCount; }
int EducationSystem::getCourseCount() const { return courseCount; }
int EducationSystem::getEnrollmentCount() const { return enrollmentCount; }
int EducationSystem::getFacultyCount() const { return facultyCount; }
