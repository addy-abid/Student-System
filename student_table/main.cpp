#include <iostream>
#include "student.hpp"

int main() {
    Student student;
    
    student.SetAge(26);
    
    cout << "Age: " << student.GetAge() << endl;

    std::cout << "Hello, World!\n";
    return 0;
}
