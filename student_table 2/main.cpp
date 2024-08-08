#include <iostream>
#include "student.hpp"
#include "roster.hpp"

int main() {
   cout <<"Course Title: C867 - SCRIPTING AND PROGRAMMING - APPLICATIONS"<< endl;
   cout << "Language: C++ " << endl;
   cout << "Student ID: 007564389" << endl;
   cout << "Student Name: Adnan Abid\n" << endl;

   Roster * classRoster = new Roster(5);

    
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Adnan,Abid,aabid4@wgu.edu,26,30,25,41,SOFTWARE"
    };
    
    for (int i = 0; i < 5; i++) {
        classRoster->parse(studentData[i]);
    };

     
    classRoster->printAll();
    cout << "\n" << endl;

      
        classRoster->printInvalidEmails();

        for (int i = 0; i < 5; i++) {

            classRoster->printAverageDaysInCourse(classRoster->GetStudentId(i));
        }
        cout << endl;
        cout << endl;

        classRoster->printByDegreeProgram(SOFTWARE);
        cout << endl;
        cout << endl;
        
        classRoster->remove("A3");
        cout << endl;
        cout << endl;

        classRoster->printAll();
        cout << endl;
        cout << endl;
    
        classRoster->remove("A3");
        cout << endl;

        

       //destructor
        classRoster->~Roster();
        delete classRoster;

}
