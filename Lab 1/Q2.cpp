#include <iostream>
#include <vector>
using namespace std;

double calculateGPA(double T, int validGrades, int creditHour) {
    return T / (validGrades * creditHour);
}

int main() {
    double marks[][5] = {
        {3.66, 3.33, 4.0, 3.0, 2.66},
        {3.33, 3.0, 3.66, 3.0, -1},
        {4.0, 3.66, 2.66, -1, -1},
        {2.66, 2.33, 4.0, -1, -1},
        {3.33, 3.66, 4.0, 3.0, 3.33}
    };
    string names[5] = { "Ali", "Hiba", "Asma", "Zain", "Faisal" };

    cout << "Name\t\tGPA" << endl;
    
    for (int student = 0; student < 5; student++) {
        double T = 0.0;
        int validGrades = 0;
        int creditHours = 3;
        for (int course = 0; course < 5; course++) {
            if (marks[student][course] != -1) {
                validGrades++;
                T += creditHours * marks[student][course];
            }
        }
        cout << names[student] << "\t\t" << calculateGPA(T, validGrades, creditHours) << endl;
    }

    return 0;
}
