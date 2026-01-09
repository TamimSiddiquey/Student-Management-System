#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <utility>

using namespace std;

const int MAX_STUDENTS = 100;

// BASE CLASS — Demonstrates ABSTRACTION
class Pupil {
protected:
    string name;
public:

    // Constructor
    Pupil() {}
    Pupil(string n) : name(n) {}

    // Virtual function
    // Enables runtime POLYMORPHISM
    virtual void display() {
        cout << "Name: " << name;
    }
};
// DERIVED CLASS — INHERITANCE (Student inherits from Pupil)
class Student : public Pupil {
private:
    int id;
    double cgpa;
    string department;
    bool isActive;

    // Friend Function
    friend void showStudentPrivateInfo(Student s);

    // Friend Class
    friend class StudentManager;

public:

    // Constructor Overloading
    Student() : id(0), cgpa(0.0), isActive(true) {}

    Student(string n, int i, double c, string d)
        : Pupil(n), id(i), cgpa(c), department(d), isActive(true) {}

    // Destructor
    ~Student() {
        if (!isActive) {
            cout << "Student record (ID: " << id << ") permanently deleted from memory" << endl;
        }
    }

    // Marking object inactive
    void markForDeletion() { isActive = false; }

    bool getActiveStatus() { return isActive; }

    // Function Overloading (2 versions of setInfo)
    void setInfo(string n, int i) {
        name = n;
        id = i;
        isActive = true;
    }

    void setInfo(string n, int i, double c, string d) {
        name = n;
        id = i;
        cgpa = c;
        department = d;
        isActive = true;
    }

    // Runtime Polymorphism — overridden function
    void display() override {
        if (isActive) {
            Pupil::display();
            cout << ", ID: " << id << ", CGPA: " << cgpa
                 << ", Department: " << department << endl;
        }
    }

    // Operator Overloading (Topic: OPERATOR OVERLOADING)
    bool operator==(int searchId) {
        return id == searchId && isActive;
    }

    bool operator==(string dept) {
        return department == dept && isActive;
    }
};
// Friend Function implementation
void showStudentPrivateInfo(Student s) {
    cout << "ID: " << s.id << " | CGPA: " << s.cgpa << endl;
}
// StudentManager — FRIEND CLASS to Student
class StudentManager {
private:

    Student students[MAX_STUDENTS];
    int count;

    vector<string> logs;                 // STL: vector
    vector<pair<int,string>> idDept;     // STL: pair inside vector
    set<string> departments;             // STL: set

public:

    // Constructor
    StudentManager() : count(0) {
        addStudent("Tamim Siddiquey", 1005, 2.77, "CSE");
        addStudent("Riad", 1010, 3.69, "EEE");
        addStudent("Arnab Dey", 1005, 3.41, "CE");
        addStudent("Sandhi", 1006, 3.25, "CSE");
    }

    // Destructor
    ~StudentManager() {
        cout << "\nCleaning up student manager..." << endl;
    }
    void addStudent(string name, int id, double cgpa, string dept) {
        if (count < MAX_STUDENTS) {

            students[count].setInfo(name, id, cgpa, dept);
            count++;

            cout << "Student added successfully!" << endl;

            // STL vector
            logs.push_back("Added student: " + name + " (ID: " + to_string(id) + ")");

            // STL vector<pair>
            idDept.push_back({id, dept});

            // STL set
            departments.insert(dept);

        } else {
            cout << "Database full! Cannot add more students." << endl;
        }
    }

    // Delete student by ID
    void deleteStudent(int id) {
        bool found = false;
        int deleteCount = 0;

        cout << "\nSearching for students with ID: " << id << " to delete..." << endl;

        for (int i = 0; i < count; i++) {

            // Operator overloaded == is used here
            if (students[i] == id) {
                found = true;
                students[i].display();

                char choice;
                cout << "Delete this student? (y/n): ";
                cin >> choice;

                if (choice == 'y' || choice == 'Y') {
                    students[i].markForDeletion();

                    logs.push_back("Deleted student ID: " + to_string(id));
                    deleteCount++;

                    // Object goes out of scope → destructor called
                    Student temp = students[i];
                }
            }
        }

        if (!found) cout << "No active students found!" << endl;
        else cout << "Deleted " << deleteCount << " student(s)." << endl;
    }

    // Search overloaded (int)
    void searchStudent(int id) {
        bool found = false;
        cout << "\nSearching for ID: " << id << endl;

        for (int i = 0; i < count; i++) {
            // Operator overloading used again
            if (students[i] == id) {
                found = true;
                students[i].display();

                // Friend Function used here
                cout << "   Private info: ";
                showStudentPrivateInfo(students[i]);
            }
        }

        if (!found) cout << "No active students found!" << endl;
    }

    // Search overloaded (string)
    void searchStudent(string department) {
        bool found = false;
        cout << "\nSearching in department: " << department << endl;

        for (int i = 0; i < count; i++) {
            if (students[i] == department) {  // string operator
                found = true;
                students[i].display();
            }
        }

        if (!found) cout << "No active students found!" << endl;
    }

    void displayAll() {
        cout << "\nALL ACTIVE STUDENTS" << endl;
        bool active = false;

        for (int i = 0; i < count; i++) {
            if (students[i].getActiveStatus()) {
                cout << i+1 << ". ";
                students[i].display();
                active = true;
            }
        }

        if (!active) cout << "No students!" << endl;
    }

    int getCount() {
        int activeCount = 0;
        for (int i = 0; i < count; i++)
            if (students[i].getActiveStatus()) activeCount++;
        return activeCount;
    }

    void showLogs() {
        cout << "\nACTION LOGS\n";
        for (string s : logs)
            cout << "- " << s << endl;
    }

    // STL set demonstration
    void showDepartments() {
        cout << "\nUNIQUE DEPARTMENTS\n";
        for (auto &d : departments)
            cout << "- " << d << endl;
    }
};
void showMenu() {
    cout << "\nSTUDENT MANAGEMENT SYSTEM:\n";
    cout << "1. Add Student\n";
    cout << "2. Search by ID\n";
    cout << "3. Search by Department\n";
    cout << "4. Display All Students\n";
    cout << "5. Show Total Students\n";
    cout << "6. Delete Student by ID\n";
    cout << "7. Show Logs\n";
    cout << "8. Show Departments\n";
    cout << "9. Exit\n";
    cout << "Choose an option: ";
}
int main() {

    StudentManager manager;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch(choice) {

            case 1: {
                string name, dept;
                int id;
                double cgpa;

                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);

                cout << "Enter ID: ";
                cin >> id;

                cout << "Enter CGPA: ";
                cin >> cgpa;

                cout << "Enter department: ";
                cin.ignore();
                getline(cin, dept);

                manager.addStudent(name, id, cgpa, dept);
                break;
            }

            case 2: {
                int searchId;
                cout << "Enter student ID: ";
                cin >> searchId;
                manager.searchStudent(searchId);
                break;
            }

            case 3: {
                string dept;
                cout << "Enter department: ";
                cin.ignore();
                getline(cin, dept);
                manager.searchStudent(dept);
                break;
            }

            case 4:
                manager.displayAll();
                break;

            case 5:
                cout << "Total active students: " << manager.getCount() << endl;
                break;

            case 6: {
                int deleteId;
                cout << "Enter ID to delete: ";
                cin >> deleteId;
                manager.deleteStudent(deleteId);
                break;
            }

            case 7:
                manager.showLogs();
                break;

            case 8:
                manager.showDepartments();
                break;

            case 9:
                cout << "Thank you for using Student Management System!" << endl;
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 9);

    return 0;
}
