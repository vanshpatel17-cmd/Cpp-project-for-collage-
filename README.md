# Course Registration System (CPP11)

**Student Name:** Vansh Patel  
**Enrollment Number:** IU2541230014  
**Project Code:** CPP11  
**Course:** Object-Oriented Programming with C++ | Guided Project (Semester 3)  
**Institute:** Indus Institute of Technology & Engineering (IITE), Indus University  
**GitHub Repository:** [https://github.com/vanshpatel17-cmd/Cpp-project-for-collage-](https://github.com/vanshpatel17-cmd/Cpp-project-for-collage-)  

---

## 📌 Project Overview
The **Course Registration System** is a modular, console-based academic management engine developed in modern C++ (C++17). It models real-world university course enrollment, catalog management, credit ceiling enforcement (max 24 credits), seat availability tracking, course withdrawal/drop workflows, and academic reporting.

---

## 📁 Repository Structure
```
├── Source/             # Modular C++ header and implementation files (comment-free student style)
│   ├── Exceptions.h    # Custom exception hierarchy
│   ├── Person.h/.cpp   # Base person entity with virtual functions
│   ├── Student.h/.cpp  # Derived student entity with credit limit tracking
│   ├── Faculty.h/.cpp  # Derived faculty instructor entity
│   ├── Course.h/.cpp   # Course entity with dynamic array for student IDs (Rule of Three)
│   ├── Enrollment.h/.cpp # Transaction entity & printable registration slip
│   ├── FileManager.h/.cpp# Flat-file database serializer and parser
│   ├── EducationSystem.h/.cpp # Central controller facade and polymorphic engine
│   └── main.cpp        # Application entry point and interactive 9-option menu loop
├── Data/               # Flat-file database repository (pipe-delimited)
│   ├── students.txt    # Persisted student profiles
│   ├── courses.txt     # Persisted course catalog and rosters
│   ├── faculty.txt     # Persisted faculty advisors
│   └── enrollments.txt # Persisted registration transactions
├── Diagrams/           # High-resolution UML Diagrams
│   ├── UseCase.png     # Use Case Diagram (2 actors, 7 use cases)
│   ├── ClassDiagram.png# Full Class Hierarchy with visibility and associations
│   ├── Sequence1.png   # Sequence Diagram 1: Main Transaction (Course Registration)
│   └── Sequence2.png   # Sequence Diagram 2: Transaction 2 (Course Withdrawal / Drop)
├── Executable/         # Compiled binary
│   └── Project.exe     # Standalone executable
├── Screenshots/        # Program execution screenshots (Figures 1 to 7)
├── ProjectReport.pdf   # Comprehensive 15-page academic project report
├── ProjectReport.docx  # Word document version of report
└── README.txt          # Plain text system manual
```

---

## ⚙️ Compilation Instructions

### Prerequisites
* GCC / G++ (C++17 standard) or MinGW-w64

### Build Command
```powershell
g++ -std=c++17 -Wall -Wextra Source\*.cpp -o Executable\Project.exe
```

### Run Command
```powershell
.\Executable\Project.exe
```

---

## 📋 Interactive Menu Options
1. **Add Record:** Add new Student, Course, or Faculty records.
2. **Display Records:** Tabular display of Students, Courses, Faculty, Enrollments, and Polymorphic Person view.
3. **Search Record:** Fast search by Student ID, Course Code, or Enrollment ID.
4. **Update Record:** Update student contact/department or course seat capacity.
5. **Delete Record:** Delete obsolete student or course records.
6. **Main Transaction (Course Enrollment):** Select student and course, verify prerequisites, seats, credit limits (max 24), and generate official registration slip.
7. **Report:** Real-time course seat occupancy percentage and student credit load matrix.
8. **Save / Load Data:** Explicit manual save and reload from `Data/` flat files.
9. **Exit:** Auto-saves all updated records to disk and gracefully closes.

---

## 💡 Object-Oriented Programming (OOP) Concepts Demonstrated
* **Encapsulation:** Private and protected data members accessible only via public getters/setters.
* **Constructors & Destructors:** Default and parameterized constructors; deterministic memory cleanup.
* **Inheritance:** `Student` and `Faculty` publicly inherit from `Person`.
* **Runtime Polymorphism:** Base class pointer `Person*` binds to derived objects to dynamically invoke `display()` and evaluate registration eligibility.
* **Dynamic Memory Management:** Dynamic allocation with `new[]` and `delete[]` in `Course` and `EducationSystem`; full **Rule of Three** compliance.
* **File Handling:** Persistent state stored using `ifstream` and `ofstream` with pipe (`|`) delimiters.
* **Custom Exception Handling:** Hierarchical exceptions derived from `std::runtime_error`.

---

## 👨‍💻 Student Details
* **Student Name:** Vansh Patel
* **Enrollment Number:** IU2541230014
* **Course:** Object-Oriented Programming with C++ (Sem 3)
* **Institute:** Indus Institute of Technology & Engineering (IITE)
* **GitHub Repository:** [https://github.com/vanshpatel17-cmd/Cpp-project-for-collage-](https://github.com/vanshpatel17-cmd/Cpp-project-for-collage-)
