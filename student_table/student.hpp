#include <iostream>
#include <string>
#ifndef STUDENT_H
#define STUDENT_H
using namespace std;

class Student {
    private:
        int studentId;
        string firstName;
        string lastName;
        string emailAddress;
        int age;
        int daysToComplete[5];
        string degreeProgram;
    public:
        int GetStudentId() const;
        string GetFirstName() const;
        string GetLastName() const;
        string GetEmailAddress() const;
        int GetAge() const;
        int* GetDaysToComplete() const;
        string GetDegreeProgram() const;




        void SetStudentId(int studentId);
        void SetFirstName(string firstName);
        void SetLastName(string lastName);
        void SetEmailAddress(string emailAddress);
        void SetAge(int age);
        void SetDaysToComplete(int* daysToComplete);
        void SetDegreeProgram(string degreeProgram);
};

#endif
