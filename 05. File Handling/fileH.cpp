#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    int age;
};

int main() {
    ofstream outFile("student_info.txt", ios::app); 

    if (!outFile) {
        cout << "Unable to open file for writing." << endl;
        return 1;
    }

    Student student;
    cout << "Enter student ID: ";
    cin >> student.id;

    cout << "Enter student name: ";
    // cin.ignore(); 
    // getline(cin, student.name);
    cin >> student.name;

    cout << "Enter student age: ";
    cin >> student.age;

    outFile << "Student ID: " << student.id << endl;
    outFile << "Name: " << student.name << endl;
    outFile << "Age: " << student.age << endl;
    outFile << "--------------------------" << endl;

    cout << "Student information stored successfully." << endl;

    outFile.close();

    return 0;
}