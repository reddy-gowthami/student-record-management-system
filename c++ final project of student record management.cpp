#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Student {
private:
    string name;
    string rollNumber;
    string department;
    string email;

public:
    Student(string n, string r, string d, string e)
        : name(n), rollNumber(r), department(d), email(e) {}

    string const getName() { return name; }
    string getRollNumber() const { return rollNumber; }
    string getDepartment() const { return department; }
    string getEmail() const { return email; }
};
class StudentDatabase {
private:
    vector<Student> students;
public:
    bool isRollNumberUnique(const string& rollNumber) const {
        return find_if(students.begin(), students.end(), [rollNumber](const Student& student) {
            return student.getRollNumber() == rollNumber;
        }) == students.end();
    }
    void addStudent(const Student& newStudent) {
        if (!isRollNumberUnique(newStudent.getRollNumber())) {
            cout << "Error: Roll number must be unique. Student not added." << endl;
        } else {
            students.push_back(newStudent);
            cout << "Student added successfully." << endl;
        }
    }
    void searchStudent(string rollNumber) {
        auto it = find_if(students.begin(), students.end(), [rollNumber](const Student& student) {
            return student.getRollNumber() == rollNumber;
        });
        if (it != students.end()) {
            cout << "Student found." << endl;
        } else {
            cout << "Student not found." << endl;
        }
    }
    void deleteStudent(string rollNumber) {
        auto it = find_if(students.begin(), students.end(), [rollNumber](const Student& student) {
            return student.getRollNumber() == rollNumber;
        });
        if (it != students.end()) {
            students.erase(it);
            cout << "Student deleted successfully." << endl;
        } else {
            cout << "Error: Student not found." << endl;
        }
    }
    void displayStudentDetails(string rollNumber) {
        auto it = find_if(students.begin(), students.end(), [rollNumber](const Student& student) {
            return student.getRollNumber() == rollNumber;
        });
        if (it != students.end()) {
            cout << "Student details:" << endl;
            cout << "Name: " << it->getName() << endl;
            cout << "Roll Number: " << it->getRollNumber() << endl;
            cout << "Department: " << it->getDepartment() << endl;
            cout << "Email: " << it->getEmail() << endl;
        } else {
            cout << "Student not found." << endl;
        }
    }
};
int main() {
    StudentDatabase database;
    while (true) {
        cout << "\nMenu Options:" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Search Student" << endl;
        cout << "3. Delete Student" << endl;
        cout << "4. Student Details" << endl;
        cout << "5. Exit" << endl;
        int choice;
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string name, department, email;
                string rollNumber;
                cout << "Enter student name: ";
                cin >> name;
                cout << "Enter student roll number: ";
                while (!(cin >> rollNumber) || !database.isRollNumberUnique(rollNumber)){
                    cout << "Invalid or non-unique roll number. Please enter a valid and unique integer for roll number: ";
                }
                cout << "Enter student department: ";
                cin >> department;
                cout << "Enter student email: ";
                cin >> email;
                Student newStudent(name, rollNumber, department, email);
                database.addStudent(newStudent);
                break;
            }
            case 2: {
                string rollNumber;
                cout << "Enter student roll number to search: ";
                while (!(cin >> rollNumber)) {
                    cout << "Invalid input. Please enter a valid integer for roll number: ";
                }
                database.searchStudent(rollNumber);
                break;
            }
            case 3: {
                string rollNumber;
                cout << "Enter student roll number to delete: ";
                while (!(cin >> rollNumber)) {
                    cout << "Invalid input. Please enter a valid integer for roll number: ";
                }
                database.deleteStudent(rollNumber);
                break;
            }
            case 4: {
                string rollNumber;
                cout << "Enter student roll number for details: ";
                while (!(cin >> rollNumber)) {
                    cout << "Invalid input. Please enter a valid integer for roll number: ";
                }
                database.displayStudentDetails(rollNumber);
                break;
            }
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
    }
    return 0;
}