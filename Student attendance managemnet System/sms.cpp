
#include <iostream>
#include <string>
#include <vector>

// Structure to represent a student
struct Student {
    std::string name;
    bool present;
};

// Function to mark attendance for a student
void markAttendance(std::vector<Student>& students, const std::string& name) {
    for (auto& student : students) {
        if (student.name == name) {
            student.present = true;
            std::cout << "Attendance marked for " << name << std::endl;
            return;
        }
    }
    std::cout << "Student " << name << " not found." << std::endl;
}

// Function to display attendance for all students
void displayAttendance(const std::vector<Student>& students) {
    for (const auto& student : students) {
        std::cout << "Name: " << student.name << ", Attendance: " << (student.present ? "Present" : "Absent") << std::endl;
    }
}

int main() {
    std::vector<Student> students;

    // Add some sample students
    students.push_back({"arya", false});
    students.push_back({"janvi", false});
    students.push_back({"xyz", false});

    // Display menu
    int choice;
    std::string name;
    do {
        std::cout << "\nAttendance Management System\n";
        std::cout << "\n Here only the attendance mark of the student whose name is written in the program";
        std::cout << "1. Mark Attendance\n";
        std::cout << "2. Display Attendance\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice (1-3): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter student name: ";
                std::cin.ignore();  // Ignore the newline character left in the input buffer
                std::getline(std::cin, name);
                markAttendance(students, name);
                break;
            case 2:
                displayAttendance(students);
                break;
            case 3:
                std::cout << "Exiting the program. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 3);

return 0;
}

