#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void gradeBook(double grades[5][4], int numStudents, string studentNames[5]) {
    double averageGrades[5];
    double gradeSum = 0;
    char letterGrades[5];
    for (int index = 0; index < numStudents; index++) {
        for (int j = 0; j < 4; j++) {
            gradeSum = gradeSum + grades[j][index];
        }
        averageGrades[index] = gradeSum / 4;
        gradeSum = 0;
    }

    for (int index = 0; index < numStudents; index++) {
        if (averageGrades[index] >= 90) {
            letterGrades[index] = 'A';
        }
        else if (averageGrades[index] >= 80) {
            letterGrades[index] = 'B';
        }
        else if (averageGrades[index] >= 70) {
            letterGrades[index] = 'C';
        }
        else if (averageGrades[index] >= 60) {
            letterGrades[index] = 'D';
        }
        else {
            letterGrades[index] = 'F';
        }
    }

    cout << "Name & Letter grade\n";
    cout << "--------------------\n";
    for (int index = 0; index < numStudents; index++) {
        cout << studentNames[index] << ": " << letterGrades[index] << endl;
    }
    if (numStudents == 0) {
        cout << "No students names or grades have been inputed!\n";
    }


}

void menu() {
    // Prints main menu with options    
    cout << "Make a Selection\n";
    cout << "----------------\n";
    cout << "1. Add Student\n";
    cout << "2. Add Grade to Student\n";
    cout << "3. See Gradebook\n";
    cout << "4. Quit\n";
}

int main() {
    int numStudents = 0; // Initializes number of students
    string studentNames[5]; // Creates array of strings to contain names
    double grades[5][4]; // Creats 2D array to contain grades
    bool gradeBookOn = true; // Keeps program on

    string name;

    do { // Do-while loop ensures program runs at least once
        // Gets input from user
        int selection = 0;
        system("cls");
        while (selection < 1 || selection > 4) {
            menu(); // Prints main menu with options
            cout << "What do you want to do?: ";
            cin >> selection;
            if (selection > 0 && selection < 5) {
                switch (selection) {
                case(1):
                    system("cls");
                    if (numStudents > 4) {
                        cout << "Too many students! Please Reset Program!\n";
                        system("pause");
                        break;
                    }
                    cout << "Enter the name of the new Student: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    getline(cin, name);
                    studentNames[numStudents] = name;
                    numStudents++;
                    break;

                case(2): {
                    system("cls");
                    if (numStudents == 0) {
                        cout << "No students to input grades!\n";
                        system("pause");
                        break;
                    }
                    int columnMarker = -1;

                    while (columnMarker < 1 || columnMarker > numStudents) {
                        system("cls");
                        if (columnMarker != -1) {
                            cout << "Invalid Choice!\n";
                        }
                        for (int index = 0; index < numStudents; index++) {
                            cout << index + 1 << ". " << studentNames[index] << "\n";
                        }
                        cout << "Which student do you want to input grades in for? \n";
                        cout << "Enter a number (1 - " << numStudents << "): ";
                        cin >> columnMarker;
                        
                    }
                    columnMarker--;

                    for (int index = 0; index < 4; index++) {
                        grades[index][columnMarker] = -1;
                        while (grades[index][columnMarker] < 0 || grades[index][columnMarker] > 100) {
                            cout << "Enter grade " << index + 1 << ": ";
                            cin >> grades[index][columnMarker];
                            if ((grades[index][columnMarker] < 0 || grades[index][columnMarker] > 100)) {
                                cout << "Invalid Grade! Try again!\n";
                            }
                        }

                    }
                    break;
                }
                case(3):
                    system("cls");
                    gradeBook(grades, numStudents, studentNames);
                    system("pause");
                    break;

                case(4): {
                    return 0;
                }
                }
            }
            else {

                cout << "Invalid Selection! " << selection << " Try Again!\n";
            }
        }

    } while (gradeBookOn == true);
}