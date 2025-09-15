
#include <iostream>
#include <cstring>   // for strlen, strcpy
#include <string>

using std::cout, std::cin, std::endl, std::string, std::strlen, std::strcpy, std::getline;

// TODO: function prototypes
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity);
void updateGPA(double* gpaPtr, double newGpa);
void printStudent(const char* name, const double& gpa);
double averageGPA(const double gpas[], int size);

// TODO: implement addStudent
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity) {
    if (size >= capacity) {
        throw "Error: Case1: Max student capacity reached; List full";
    }
    names[size] = new char[strlen(name) + 1];
    strcpy(names[size], name);
    gpas[size] = gpa;
    size += 1;
}
// TODO: implement updateGPA
void updateGPA(double* gpaPtr, double newGpa) {
    if (gpaPtr != nullptr) {
        *gpaPtr = newGpa;
    }
}
// TODO: implement printStudent
void printStudent(const char* name, const double& gpa) {
    cout << "Name: " << name << ", ";
    cout << "GPA: " << gpa << endl; 
}
// TODO: implement averageGPA
double averageGPA(const double gpas[], int size) {
    if (size == 0) {
        throw "Error: Case4: No students. Add a student!";
    }
    double result = 0.0;
    for (int i = 0; i < size; i++) {
        result += gpas[i];
    }
    return result / size;
}


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]);
    char* names[capacity];
    double gpas[capacity];
    int size = 0;

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // TODO: implement menu logic
                // gather user response and store
                cout << "Enter student name:" << endl;
                string name_str;
                cin >> name_str;
                
                cout << "Enter student GPA:" << endl;
                double gpa;
                cin >> gpa;
                            
                // convert str name to char* name
                char* name = new char[name_str.size() + 1];
                strcpy(name, name_str.c_str());
                            
                // call function and increment size
                try {
                    addStudent(name, gpa, names, gpas, size, capacity);
                    cout << "Student: '" << name_str << "' has been added successfully." << endl << endl;
                    delete[] name;
                } catch (const char* msg) {
                    cout << msg << endl << endl;
                }
                break;
            }
            case 2: {
                // TODO: implement menu logic
                
                if (size == 0) {
                    cout << "Error: Case2: No students to change; add a student!" << endl << endl;
                    break;
                }
                // collect user input
                cout << "Please provide the student's index to change gpa:" << endl;
                int index;
                cin >> index;
                
                // ensure valid index is passed
                if (index < 0 || index >= size) {
                    cout << "Error: Case2: There is no value stored at index " << index << endl << endl;
                    break;
                }

                // get new gpa value
                cout << "Please enter the new GPA:" << endl;
                double new_gpa = 0.0;
                cin >> new_gpa;
                double old_gpa = gpas[index]; // store old for print clarity
                
                // updateGPA function call
                updateGPA(&gpas[index], new_gpa);
                
                // show user result
                cout << "GPA (for '" << names[index] << "') updated: " << old_gpa << "->" << gpas[index] << endl << endl;
                break;
            }
            case 3: {
                // TODO: implement menu logic
                // call printStudent
                if (size == 0) {
                    cout << "Error: Case3: No students have been added yet; nothing to print." << endl << endl;
                    break;
                }
                for (int i = 0; i < size; i++) {
                    try {
                        printStudent(names[i], gpas[i]);
                    } catch (const char* msg) {
                        cout << msg << endl;
                    }
                }
                cout << endl;
                break;
            }
            case 4: {
                // TODO: implement menu logic
                try {
                    cout << "Average GPA: " << static_cast<int>(averageGPA(gpas, size)) << endl << endl;
                } catch (const char* msg) {
                    cout << msg << endl << endl;
                }
                break;

            }
            case 5: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    } while (choice != 5);

    // TODO: free memory
    for (int i = 0; i < size; i++) {
        delete[] names[i];
    }

    return 0;
}
