# 🎓 Student Management System (C++)

A **modern, console-based Student Management System** implemented in **C++**, designed to demonstrate **Object-Oriented Programming (OOP)** concepts and effective use of the **C++ Standard Template Library (STL)**.

This project is ideal for **academic submission**, **GitHub portfolio**, and **OOP concept demonstration**.

---

## ✨ Key Features

- ➕ Add student records
- 🔍 Search students by **ID** or **Department**
- 🗑️ Delete students using a **soft-delete mechanism**
- 📋 Display all active students
- 📊 Count total active students
- 🧾 Maintain action logs
- 🏫 Display unique departments
- 🧠 Safe memory handling using constructors & destructors

---

## 🧩 Object-Oriented Programming Concepts

| Concept | Implementation |
|------|---------------|
| **Abstraction** | `Pupil` base class |
| **Inheritance** | `Student` inherits from `Pupil` |
| **Encapsulation** | Private class members |
| **Polymorphism** | Virtual `display()` function |
| **Function Overloading** | `setInfo()` methods |
| **Operator Overloading** | `==` for ID & Department |
| **Friend Function** | `showStudentPrivateInfo()` |
| **Friend Class** | `StudentManager` |
| **Constructor & Destructor** | Object lifecycle handling |

---

## 🧰 STL Usage

- `vector<string>` → Action logs
- `vector<pair<int, string>>` → Student ID–Department mapping
- `set<string>` → Unique department list

---

## 🏗️ Project Structure

📦 Student-Management-System
┣ 📜 main.cpp
┣ 📜 README.md


---

## 🖥️ Menu Interface



STUDENT MANAGEMENT SYSTEM:

Add Student

Search by ID

Search by Department

Display All Students

Show Total Students

Delete Student by ID

Show Logs

Show Departments

Exit


---

## ⚙️ How to Compile & Run

### 🔹 Using GCC
```bash
g++ main.cpp -o student_manager
./student_manager

🔹 Requirements

C++11 or later

GCC / Clang / MSVC

🧪 Sample Preloaded Data

The program starts with predefined students for testing:

Tamim Siddiquey — CSE

Riad — EEE

Arnab Dey — CE

Sandhi — CSE

🚀 Future Enhancements

File handling (save/load student data)

Exception handling

Sorting and filtering options

GUI or Web-based interface

Database integration

👨‍💻 Author

Tamim Siddiquey
🎓 Computer Science & Engineering
📍 Bangladesh

📜 License

This project is intended for educational use.
You are free to use, modify, and improve it.
