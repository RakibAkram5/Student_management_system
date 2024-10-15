# Student Database Management System

This is a simple C++ program that allows you to manage student records. The program provides functionalities to add, display, update, delete, and search for students by CGPA. It stores student data in a text file (`student_database.txt`).

## Features

1. **Add Student Record**: Allows the user to add a new student to the database.
2. **Display All Student Records**: Shows all student records stored in the database.
3. **Search by CGPA**: Finds students with a specific CGPA.
4. **Update Student Information**: Allows the user to update an existing student's information.
5. **Delete Student Record**: Deletes a student from the database using their student ID.
6. **Exit**: Terminates the program.

## Code

```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void addstudent() {
    string id;
    string name;
    int age;
    int credit_hours;
    double cgpa;
    ofstream fout("student_database.txt", ios::app);
    if (!fout) {
        cout << "Error opening File...." << endl;
        return;
    }
    cout << "Enter Student ID: ";
    cin >> id;
    cout << "Enter the Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Your age: ";
    cin >> age;
    cout << "Enter Your CGPA: ";
    cin >> cgpa;
    cout << "Enter Credit Hours: ";
    cin >> credit_hours;

    fout << id << "\t" << name << "\t" << age << "\t" << cgpa << "\t" << credit_hours << endl;
    fout.close();
    cout << "Student Record added Successfully!" << endl;
}

void displayallstudents() {
    string id;
    string name;
    double cgpa;
    char heading[100];
    int credit_hours, age;
    ifstream fin("student_database.txt");
    if (!fin) {
        cout << "Error opening File!" << endl;
        return;
    }
    cout << "ALL Student records: " << endl;
    cout << "ID\tName
