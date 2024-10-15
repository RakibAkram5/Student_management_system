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
    cout << "ID\tName\tAge\tCGPA\tCredit Hours" << endl;
    while (fin >> id >> name >> age >> cgpa >> credit_hours) {
        cout << id << "\t" << name << "\t" << age << "\t" << cgpa << "\t" << credit_hours << endl;
    }
    fin.close();
}

void updatestudent() {
    ifstream fin("student_database.txt");
    ofstream tempfile("temp.txt");
    if (!fin || !tempfile) {
        cout << "Error Opening file" << endl;
        return;
    }
    string id, name, targetID;
    double cgpa;
    int age, credit_hours;
    bool found = false;
    cout << "Enter the Student ID To Update: ";
    cin >> targetID;
    while (fin >> id >> name >> age >> cgpa >> credit_hours) {
        if (id == targetID) {
            found = true;
            cout << "Enter new Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter New Age: ";
            cin >> age;
            cout << "Enter New CGPA: ";
            cin >> cgpa;
            cout << "Enter New Credit Hours: ";
            cin >> credit_hours;
        }
        tempfile << id << "\t" << name << "\t" << age << "\t" << cgpa << "\t" << credit_hours << endl;
    }
    fin.close();
    tempfile.close();
    if (found) {
        remove("student_database.txt");
        rename("temp.txt", "student_database.txt");
        cout << "Student record updated Successfully." << endl;
    }
    else {
        remove("temp.txt");
        cout << "Student ID Not Found" << endl;
    }
}

void searchbycgpa() {
    ifstream fin("student_database.txt");
    if (!fin) {
        cout << "Error opening file." << endl;
        return;
    }
    string id, name;
    int age, credit_hour;
    double cgpa;
    bool found = false;
    double targetCGPA;
    cout << "Enter CGPA to search: ";
    cin >> targetCGPA;
    while (fin >> id >> name >> age >> cgpa >> credit_hour) {
        if (cgpa == targetCGPA) {
            cout << id << "\t" << name << "\t" << age << "\t" << cgpa << "\t" << credit_hour << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No student found with CGPA: " << targetCGPA << endl;
    }
    fin.close();
}

void deletestudent() {
    ifstream fin("student_database.txt");
    ofstream fout("temp.txt");
    string id, name, targetID;
    int age, credit_hours;
    double cgpa;
    bool found = false;
    cout << "Enter the Student ID to Delete: ";
    cin >> targetID;
    while (fin >> id >> name >> age >> cgpa >> credit_hours) {
        if (id != targetID) {
            fout << id << "\t" << name << "\t" << age << "\t" << cgpa << "\t" << credit_hours << endl;
        }
        else {
            found = true;
        }
    }
    fin.close();
    fout.close();
    if (found) {
        remove("student_database.txt");
        rename("temp.txt", "student_database.txt");
        cout << "Student record deleted Successfully!" << endl;
    }
    else {
        remove("temp.txt");
        cout << "Student ID not Found." << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\n\t\tStudent Database Management System\t\t\n\n" << endl;
        cout << "1. Add Student Record." << endl;
        cout << "2. Display ALL Student Records." << endl;
        cout << "3. Search student by CGPA." << endl;
        cout << "4. Update Student Information." << endl;
        cout << "5. Delete Student Record." << endl;
        cout << "6. Exit." << endl;
        cout << "Enter your Choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            addstudent();
            break;
        case 2:
            displayallstudents();
            break;
        case 3:
            searchbycgpa();
            break;
        case 4:
            updatestudent();
            break;
        case 5:
            deletestudent();
            break;
        case 6:
            cout << "Exiting the program..." << endl;
            break;
        default:
            cout << "Invalid Choice! Please try again." << endl;
        }
    } while (choice != 6);
    return 0;
}
