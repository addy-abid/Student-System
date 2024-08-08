#include <iostream>
#include <string>
#ifndef STUDENT_H
#define STUDENT_H
#include "degree.h"
using namespace std;

class Student {
    private:
        string studentId;
        string firstName;
        string lastName;
        string emailAddress;
        int age;
        int daysToComplete[5];
        DegreeProgram degreeProgram;
    public:
        Student();
        Student(string studentID, string firstName, string lastName, string emailAddress, int age,int daysInCourse[], DegreeProgram degreeProgram);
    
        string GetStudentId() const;
        string GetFirstName() const;
        string GetLastName() const;
        string GetEmailAddress() const;
        int GetAge() const;
        const int* GetDaysToComplete() const;
        DegreeProgram GetDegreeProgram() const;


        void SetStudentId(string studentId);
        void SetFirstName(string firstName);
        void SetLastName(string lastName);
        void SetEmailAddress(string emailAddress);
        void SetAge(int age);
        void SetDaysToComplete(int daysToComplete1, int daysToComplete2, int daysToComplete3);
        void SetDegreeProgram(DegreeProgram degreeProgram);
    
        DegreeProgram getDegreeProgram();
    
        void print() const;
};

#endif
