#include "student.hpp"
#include "degree.h"

Student::Student() {
    this->studentId = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    this->daysToComplete[0] = 0;
    this->daysToComplete[1] = 0;
    this->daysToComplete[2] = 0;
    this->degreeProgram;
}
//parameter constructor

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram) {
    this->studentId = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->daysToComplete[0] = daysToComplete[0];
    this->daysToComplete[1] = daysToComplete[1];
    this->daysToComplete[2] = daysToComplete[2];
    this->degreeProgram = degreeProgram;
}

// Getters
string Student::GetStudentId() const {
    return studentId;
}

string Student::GetFirstName() const {
    return firstName;
}

string Student::GetLastName() const {
    return lastName;
}

string Student::GetEmailAddress() const {
    return emailAddress;
}

int Student::GetAge() const {
    return age;
}

const int* Student::GetDaysToComplete() const {
    return daysToComplete;
}

DegreeProgram Student::GetDegreeProgram() const {
    return degreeProgram;
}

// Setters
void Student::SetStudentId(string studentId) {
    this->studentId = studentId;
}

void Student::SetFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::SetLastName(string lastName) {
    this->lastName = lastName;
}

void Student::SetEmailAddress(string emailAddress) {
    this->emailAddress = emailAddress;
}

void Student::SetAge(int age) {
    this->age = age;
}

void Student::SetDaysToComplete(int daysToComplete1, int daysToComplete2, int daysToComplete3) {
    for (int i = 0; i < 3; ++i) {
        this->daysToComplete[0] = daysToComplete1;
        this->daysToComplete[1] = daysToComplete2;
        this->daysToComplete[2] = daysToComplete3;
    }
}

void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}

void Student::print() const {
    cout << "Student ID: " << studentId << " "
             << "First Name: " << firstName << " "
             << "Last Name: " << lastName << " "
             << "Email Address: " << emailAddress << " "
             << "Age: " << age << " "
             << "Days to Complete: ";
    for (int i = 0; i < 3; ++i) {
        cout << daysToComplete[i] << " ";
    }
    cout << endl;
    cout << "Degree Program: ";
    switch(degreeProgram) {
        case SECURITY: cout << "SECURITY"; break;
        case NETWORK: cout << "NETWORK"; break;
        case SOFTWARE: cout << "SOFTWARE"; break;
    }
    cout << endl;
}
