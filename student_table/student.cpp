#include "student.hpp"

// Getters
int Student::GetStudentId() const {
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

string Student::GetDegreeProgram() const {
    return degreeProgram;
}

// Setters
void Student::SetStudentId(int studentId) {
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

void Student::SetDaysToComplete(int* daysToComplete) {
    for (int i = 0; i < 5; ++i) {
        this->daysToComplete[i] = daysToComplete[i];
    }
}

void Student::SetDegreeProgram(string degreeProgram) {
    this->degreeProgram = degreeProgram;
}
