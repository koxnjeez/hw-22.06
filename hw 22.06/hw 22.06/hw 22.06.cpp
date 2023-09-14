#include <iostream>
#include <time.h>
using namespace std;

int main()
{
    const int N = 15;
    int studentGrades[N], temp, userChoise, newGrade, gradeNum, userGrades[N] = { 0 }, nUserGrades = 0, iMin, userGrades2[N] = { 0 }, nUserGrades2 = 0;
    bool isData = false, isExit = false;
    const double SchLevel = 10.7;
    float sum = 0.0;

    srand(time(0));
    do {
        cout << "Menu:\n";
        cout << "\t1. Get data\n\t2. Print data\n\t3. Pass exam once again\n\t4. Scholarship\n\t5. Linear search (grade<user input)\n\t6. Binary search (grade=user input)\n\t7. Sort\n\t8. Exit\n";

        cout << "Select menu item: ";
        cin >> userChoise;

        switch (userChoise) {
        case 1: {
            cout << "Student`s grades are generating...\n";
            for (int i = 0; i < N; i++) {
                studentGrades[i] = 1 + rand() % 12;
            }
            isData = true;
            break;
        }
        case 2: {
            if (isData) {
                cout << "Student`s grades:\n";
                for (int i = 0; i < N; i++) {
                    cout << "Grade for student #" << i + 1 << ": " << studentGrades[i] << endl;
                }
            }
            else {
                cout << "Operation disabled! First get data!\n";
            }
            break;
        }
        case 3: {
            if (isData) {
                cout << "Input grade # (1..10): ";
                cin >> gradeNum;

                if (gradeNum >= 0 && gradeNum < 10) {
                    cout << "Input new grade (1..9): ";
                    cin >> newGrade;

                    if (newGrade >= 1 && newGrade < 9) {
                        studentGrades[gradeNum] = newGrade;
                        cout << "Your change was successfully applied!\n";
                    }
                    else {
                        cout << "Wrong new grade value!\n";
                    }
                }
                else {
                    cout << "Wrong grade#!\n";
                }
            }
            else {
                cout << "Operation disabled! First get data!\n";
            }
            break;
        }
        case 4: {
            if (isData) {
                for (int i = 0; i < N; i++) {
                    sum += studentGrades[i];
                }
                sum /= N;
                if (sum >= SchLevel) {
                    cout << "Congrats! Your mean grade is " << sum << endl;
                }
                else {
                    cout << "Sorry! Your mean grade is " << sum << endl;
                }
            }
            else {
                cout << "Operation disabled! First get data!\n";
            }
            break;
        }
        case 5: {
            if (isData) {
                cout << "Input grade (key): ";
                cin >> newGrade;
                for (int i = 0; i < N; i++) {
                    if (studentGrades[i] < newGrade) {
                        userGrades[nUserGrades++] = i;
                    }
                }
                if (nUserGrades > 0) {
                    for (int i = 0; i < nUserGrades; i++) {
                        cout << "Grade for student #" << userGrades[i] << ": " << studentGrades[userGrades[i]] << endl;
                    }
                }
                else {
                    cout << "No key in data!\n";
                }
            }
            else {
                cout << "Operation disabled! First get data!\n";
            }
            break;
        }
        case 6: {
            if (isData) {
                cout << "Input grade (key): ";
                cin >> newGrade;
                for (int i = 0; i < N; i++) {
                    if (studentGrades[i] == newGrade) {
                        userGrades2[nUserGrades2++] = i;
                    }
                }
                if (nUserGrades2 > 0) {
                    for (int i = 0; i < nUserGrades2; i++) {
                        cout << "Grade for student #" << userGrades2[i] << ": " << studentGrades[userGrades2[i]] << endl;
                    }
                }
                else {
                    cout << "No key in data!\n";
                }
            }
            else {
                cout << "Operation disabled! First get data!\n";
            }
            break;
        }
        case 7: {
            if (isData) {
                for (int i = 0; i < N - 1; i++) {
                    iMin = i;
                    for (int j = i + 1; j < N; j++) {
                        if (studentGrades[j] < studentGrades[iMin]) {
                            iMin = j;
                        }
                    }
                    if (iMin != i) {
                        temp = studentGrades[iMin];
                        studentGrades[iMin] = studentGrades[i];
                        studentGrades[i] = temp;
                    }
                }
            }
            else {
                cout << "Operation disabled! First get data!\n";
            }
            break;
        }
        case 8: {
            cout << "See u!\n";
            isExit = true;
            break;
        }
        default: {
            cout << "Wrong menu item! Try again!\n";
        }
        }
    } while (!isExit);
}