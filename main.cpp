#include <iostream>
#include <random>
#include <algorithm>
#include <string>
#include <limits>
#include <cstdlib>
using namespace std;

void waitForEnter() {     // Нажатие enter
    cout << "Press Enter to continue...";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  
    cin.get();  
    system("cls");
}

int main() {
    int a, n, win=0, attempts=0; 
    cout << "Welcome to the Memory Game!" << endl << "Enter the size of an array (6-20): ";
    cin >> a;
    if(a % 2 != 0 || a < 6 || a > 20) {
        while (a % 2 != 0 || a < 6 || a > 20) {
            cout << "Your number is incorrect! write another: ";
            cin >> a;
        }
    }
    int quiz[a];
    string numbers[a];
    n = (a/2);
    for (int i = 0; i < a; i+=2) {
        quiz[i] = i;
        quiz[i+1] = i;
    }
    for (int i = 0; i < a; i++) {
        numbers[i] = "?";
    }

    random_device rd;           // shaking the array
    mt19937 g(rd());            //
    shuffle(quiz, quiz + a, g); //

    while (win == 0) {
        int num1, num2, check = 0;
        cout << "\nHere is the array: ";
        for (int i = 0; i < a; i++) {
            cout << numbers[i] << " ";
        }
        cout << "\n\nEnter the index to show: ";
        cin >> num1;
        cout << "The card at the index " << num1 << " is: " << quiz[num1];
        cout << "\n\nEnter the second index to show: ";
        cin >> num2;
        cout << "The card at the index " << num2 << " is: " << quiz[num2] << endl << endl;
        attempts ++;
        for (int i = 0; i < a; i++) {
            if (i == num1 or i == num2) {
                cout << quiz[i] << " ";
            }
            else {
                cout << numbers[i] << " ";
            }
        }
        if (quiz[num1] == quiz[num2]) {
            cout << "\nGreat the cards are matched. Continue...\n" << endl;
            numbers[num1] = to_string(quiz[num1]);
            numbers[num2] = to_string(quiz[num2]);
        }
        else {
            cout << "\nThe cards do not match! Try again!\n" << endl;
        }
        for (int i = 0; i < a; i++) {
            if (numbers[i] != "?") {
                check ++;
            }
        }
        if (check == a) {
            cout << "Congratulations! You won! here's the amount of your attempts: " << attempts << "\n";
            win = 1;
        }
        else {
            waitForEnter();
            cout << "\n\n";
        }
    }
}