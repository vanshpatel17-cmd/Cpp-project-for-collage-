================================================================================
                    COURSE REGISTRATION SYSTEM (CPP11)
================================================================================
Student Name              : Vansh Patel
Student Enrollment Number : IU2541230014
Project Code              : CPP11
Course                    : Object-Oriented Programming with C++ | Guided Project
Institute                 : Indus Institute of Technology & Engineering (IITE)
Semester                  : 3 (Cyber Security / Computer Science & Engineering)
GitHub Repository         : https://github.com/vanshpatel17-cmd/Cpp-project-for-collage-
Submission Package        : Final Project Submission
Date                      : October 12, 2026
================================================================================

1. PROJECT OVERVIEW
-------------------
The Course Registration System is a modular, console-based academic management
platform developed in standard modern C++ (C++17). It models real-world university
course enrollment, catalog management, credit ceiling enforcement (max 24 credits),
seat availability tracking, course withdrawal/drop workflows, and academic reporting.
The system features flat-file data persistence, input validation, custom exception
handling, dynamic heap memory management, and clean object-oriented architecture.


2. FOLDER STRUCTURE
-------------------
IU2541230014_CPP11_Project/
|-- Source/
|   |-- Exceptions.h          : Custom exception hierarchy (StudentNotFound, CourseFull, etc.)
|   |-- Person.h / .cpp       : Abstract base entity class with virtual display() and getRole()
|   |-- Student.h / .cpp      : Derived student class with credit limit management
|   |-- Faculty.h / .cpp      : Derived faculty entity class with department & designation
|   |-- Course.h / .cpp       : Course entity with dynamic array for enrolled student IDs
|   |-- Enrollment.h / .cpp   : Transaction entity & official ASCII registration slip generator
|   |-- FileManager.h / .cpp  : Flat-file serializer and deserializer for persistence
|   |-- EducationSystem.h/.cpp: Central controller facade, dynamic arrays, and menu handlers
|   |-- main.cpp              : Program entry point, menu loop, and lifecycle
|
|-- Data/
|   |-- students.txt          : Persisted student profiles and enrolled credit counts
|   |-- courses.txt           : Persisted course catalog, seat allocations, and rosters
|   |-- faculty.txt           : Persisted faculty instructor records
|   |-- enrollments.txt       : Persisted registration transactions and timestamps
|
|-- Diagrams/
|   |-- UseCase.png           : UML Use Case Diagram (2 actors, 7 use cases)
|   |-- ClassDiagram.png      : UML Class Diagram with visibility, inheritance, and relations
|   |-- Sequence1.png         : UML Sequence Diagram (Course Registration process)
|   |-- Sequence2.png         : UML Sequence Diagram (Course Withdrawal / Drop process)
|
|-- Executable/
|   |-- Project.exe           : Submission-standard compiled binary
|
|-- Screenshots/
|   |-- 1_MainMenu.png
|   |-- 2_DisplayCourses.png
|   |-- 3_EnrollCourse_Transaction.png
|   |-- 4_SearchRecords.png
|   |-- 5_OccupancyReport.png
|   |-- 6_DropCourse_Transaction.png
|   |-- 7_PersistenceVerification.png
|
|-- README.txt                : This instruction and documentation file
|-- README.md                 : Markdown version for GitHub repository
|-- ProjectReport.pdf         : Formal academic project report (15 pages)
|-- ProjectReport.docx        : Word document version of project report


3. GITHUB REPOSITORY & CLONING
------------------------------
Repository URL:
   https://github.com/vanshpatel17-cmd/Cpp-project-for-collage-

To clone the repository using Git:
   git clone https://github.com/vanshpatel17-cmd/Cpp-project-for-collage-.git


4. COMPILATION INSTRUCTIONS
---------------------------
To compile the source code from scratch using GNU C++ (g++):

1. Open PowerShell or Command Prompt.
2. Navigate to the project root:
   cd C:\IU2541230014\IU2541230014_CPP11_Project

3. Run the following compilation command:
   g++ -std=c++17 -Wall -Wextra Source\*.cpp -o Executable\Project.exe

4. The compilation will produce "Executable\Project.exe" with 0 errors and 0 warnings.


5. EXECUTION INSTRUCTIONS
-------------------------
Run the compiled executable:
   .\Executable\Project.exe

The system automatically loads all persisted academic records from the Data/ directory.
If running for the first time, it seeds realistic default data (Vansh Patel, Priya Sharma,
CS301 OOP C++, CS302 DSA, CS305 Cyber Security) and saves them automatically to disk.


6. MENU OPERATIONS
------------------
1. Add Record      : Register new Students, Courses, or Faculty members.
2. Display Records : View all Students, Courses, Faculty, Enrollments, or Polymorphic view.
3. Search Record   : Fast lookup by Student ID, Course Code, or Enrollment ID.
4. Update Record   : Update student contact/department or course title/seat capacity.
5. Delete Record   : Remove student profiles or obsolete course offerings.
6. Main Transaction: Interactive Course Registration with seat check, duplicate check,
                     polymorphic credit limit verification, and printable slip.
7. Report          : Real-time course seat occupancy matrix & student credit load summary.
8. Save / Load Data: Explicit manual save/reload to/from disk.
9. Exit            : Auto-saves all updated records to the Data/ folder and cleanly exits.


7. OBJECT-ORIENTED PROGRAMMING CONCEPTS DEMONSTRATED
---------------------------------------------------
- Classes & Encapsulation:
  All state data members are private/protected and accessed exclusively through
  public accessors, mutators, and operational methods.
- Constructors & Destructors:
  Default and parameterized constructors implemented across all classes. Destructors
  guarantee deterministic heap memory reclamation.
- Inheritance:
  Classes 'Student' and 'Faculty' publicly inherit from the base class 'Person',
  inheriting common personal attributes (id, name, email, contactNumber).
- Runtime Polymorphism:
  Base class 'Person' defines virtual member functions 'display()', 'getRole()', and
  'getMaxCredits()'. In EducationSystem, a base class pointer 'Person*' dynamically binds
  to derived 'Student' and 'Faculty' instances to evaluate eligibility and display profiles.
- Dynamic Memory Management:
  Class 'Course' manages a dynamic array of student IDs on the heap:
    enrolledStudentIds = new string[maxSeats];
  Safely released in the destructor '~Course()' using:
    delete[] enrolledStudentIds;
  Strict adherence to the Rule of Three with deep-copy copy constructor and copy assignment operator.
  Class 'EducationSystem' dynamically allocates and resizes entity arrays on the heap.
- Flat-File Persistence:
  Full state serialization using standard C++ 'std::ifstream' and 'std::ofstream'
  with pipe ('|') delimiters. Persistence verified across complete application restarts.
- Custom Exception Handling:
  Hierarchy of custom exception classes (CourseFullException, AlreadyEnrolledException,
  CreditLimitExceededException, StudentNotFoundException) caught cleanly with try-catch blocks.
================================================================================
