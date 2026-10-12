#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

using namespace std;

class SystemException : public runtime_error {
public:
    explicit SystemException(const string& msg) : runtime_error(msg) {}
};

class StudentNotFoundException : public SystemException {
public:
    explicit StudentNotFoundException(const string& msg = "Student ID not found in system!")
        : SystemException(msg) {}
};

class CourseNotFoundException : public SystemException {
public:
    explicit CourseNotFoundException(const string& msg = "Course ID not found in system!")
        : SystemException(msg) {}
};

class CourseFullException : public SystemException {
public:
    explicit CourseFullException(const string& msg = "Course seat capacity reached! No available seats.")
        : SystemException(msg) {}
};

class AlreadyEnrolledException : public SystemException {
public:
    explicit AlreadyEnrolledException(const string& msg = "Student is already enrolled in this course!")
        : SystemException(msg) {}
};

class NotEnrolledException : public SystemException {
public:
    explicit NotEnrolledException(const string& msg = "Student is not enrolled in this course!")
        : SystemException(msg) {}
};

class CreditLimitExceededException : public SystemException {
public:
    explicit CreditLimitExceededException(const string& msg = "Maximum semester credit limit exceeded!")
        : SystemException(msg) {}
};

class InvalidInputException : public SystemException {
public:
    explicit InvalidInputException(const string& msg = "Invalid input data provided!")
        : SystemException(msg) {}
};

#endif
