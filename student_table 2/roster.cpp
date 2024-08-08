#include <iostream>
#include <string>
#include "degree.h"
#include "student.hpp"
#include "roster.hpp"
using namespace std;

Roster::Roster(int classSize) {
    this->classSize = classSize;
    this->ind = 0;
    for (int i = 0; i < classSize; i++) {
        this->classRosterArray[i] = new Student;
    }
}

string Roster::GetStudentId(int index) {
    return classRosterArray[index]->GetStudentId();
}

void Roster::parse(string studentDataTable) {
    string sID, firstname, lastname, emailAddress;
    int studentAge, daysInCourse1, daysInCourse2, daysInCourse3;

    if (ind < classSize) {
        classRosterArray[ind] = new Student();

        int i = studentDataTable.find(",");
        sID = studentDataTable.substr(0, i);
        classRosterArray[ind]->SetStudentId(sID);

        int d = i + 1;
        i = studentDataTable.find(",", d);
        firstname = studentDataTable.substr(d, i - d);
        classRosterArray[ind]->SetFirstName(firstname);

        d = i + 1;
        i = studentDataTable.find(",", d);
        lastname = studentDataTable.substr(d, i - d);
        classRosterArray[ind]->SetLastName(lastname);

        d = i + 1;
        i = studentDataTable.find(",", d);
        emailAddress = studentDataTable.substr(d, i - d);
        classRosterArray[ind]->SetEmailAddress(emailAddress);

        d = i + 1;
        i = studentDataTable.find(",", d);
        studentAge = stoi(studentDataTable.substr(d, i - d));
        classRosterArray[ind]->SetAge(studentAge);

        d = i + 1;
        i = studentDataTable.find(",", d);
        daysInCourse1 = stoi(studentDataTable.substr(d, i - d));

        d = i + 1;
        i = studentDataTable.find(",", d);
        daysInCourse2 = stoi(studentDataTable.substr(d, i - d));

        d = i + 1;
        i = studentDataTable.find(",", d);
        daysInCourse3 = stoi(studentDataTable.substr(d, i - d));
        classRosterArray[ind]->SetDaysToComplete(daysInCourse1, daysInCourse2, daysInCourse3);

        d = i + 1;
        i = studentDataTable.find(",", d);
        string type = studentDataTable.substr(d, i - d);
        if (type == "SOFTWARE") {
            classRosterArray[ind]->SetDegreeProgram(SOFTWARE);
        } else if (type == "SECURITY") {
            classRosterArray[ind]->SetDegreeProgram(SECURITY);
        } else if (type == "NETWORK") {
            classRosterArray[ind]->SetDegreeProgram(NETWORK);
        } else {
            cout << "Degree not found" << endl;
        }
        ind++;
    }
}

void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int daysInCourse[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    classRosterArray[classSize] = new Student(studentID, firstName, lastName, email, age, daysInCourse, degreeProgram);
}

void Roster::remove(string id) {
    bool foundStudent = false;
    for (int i = 0; i < classSize; i++) {
        if (classRosterArray[i] == nullptr) {
            continue;
        } else if (id == classRosterArray[i]->GetStudentId()) {
            classRosterArray[i] = nullptr;
            foundStudent = true;
            break;
        }
    }
    if (!foundStudent) {
        cout << "Error: Student " << id << " Not Found." << endl;
    } else {
        cout << "Student " << id << " removed." << endl;
    }
}

void Roster::printAll() {
    for (int i = 0; i < classSize; i++) {
        if (classRosterArray[i] == nullptr) {
            continue;
        } else {
            classRosterArray[i]->print();
        }
    }
    cout << endl;
}

void Roster::printAverageDaysInCourse(string id) {
    for (int i = 0; i < classSize; i++) {
        if (id == classRosterArray[i]->GetStudentId()) {
            cout << id << " average days in course: "
                 << ((classRosterArray[i]->GetDaysToComplete()[0] +
                      classRosterArray[i]->GetDaysToComplete()[1] +
                      classRosterArray[i]->GetDaysToComplete()[2]) / 3)
                 << endl;
        }
    }
}

void Roster::printInvalidEmails() {
    for (int i = 0; i < classSize; ++i) {
        string emailAd = classRosterArray[i]->GetEmailAddress();
        if ((emailAd.find('@') == string::npos) || (emailAd.find(' ') != string::npos) || (emailAd.find('.') == string::npos)) {
            cout << "Invalid Email: " << classRosterArray[i]->GetStudentId() << " email address " << emailAd << " is invalid." << endl;
        }
    }
    cout << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degPro) {
    string degreeString;
    if (degPro == SECURITY) {
        degreeString = "SECURITY";
    } else if (degPro == NETWORK) {
        degreeString = "NETWORK";
    } else if (degPro == SOFTWARE) {
        degreeString = "SOFTWARE";
    } else {
        degreeString = "ERROR";
    }
    cout << "Students with degree program: " << degreeString << endl;
    int numStudents = 0;
    for (int i = 0; i < classSize; i++) {
        if (classRosterArray[i]->GetDegreeProgram() == degPro) {
            ++numStudents;
        }
    }
    if (numStudents == 0) {
        cout << "ERROR" << endl;
    }
}

// Destructor
Roster::~Roster() {
    for (int i = 0; i < 5; i++) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
