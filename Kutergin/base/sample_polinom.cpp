#include <iostream>
#include <string>
#include <limits>
#include "Polinom.h"

using namespace std;

// Функция для безопасного чтения целого числа
int getIntInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (!cin.fail())
            break;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a number." << endl;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очистка оставшегося ввода
    return value;
}

// Функция для безопасного чтения одного символа
char getCharInput(const string& prompt) {
    char c;
    while (true) {
        cout << prompt;
        cin >> c;
        if (!cin.fail())
            break;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a character." << endl;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return c;
}

// Функция для безопасного чтения вещественного числа
double getDoubleInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (!cin.fail())
            break;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Please enter a valid number." << endl;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

// Функция для безопасного чтения строки
string getLineInput(const string& prompt) {
    string line;
    cout << prompt;
    getline(cin, line);
    return line;
}

void printMenu() {
    cout << "\n===== POLYNOMIAL MANAGEMENT MENU =====\n";
    cout << "1. Add 2 polynomials\n";
    cout << "2. Subtract the second polynomial from the first one\n"; 
    cout << "3. Subtract the first polynomial from the second one\n";
    cout << "4. Multiply the first polynomial by the coefficient\n";
    cout << "5. Take the derivative of a first polynomial\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

int main()
{
    setlocale(LC_ALL, "Russian");

    string input1, input2;
    char var;
    int coef;

    while (true) {
        cout << "Please enter 2 polynomials:";
        cout << "(input format: x^2 + 2xy + 3y^2z^2)\n";
        cout << "Enter the first polynomial: \n";
        cin >> input1;
        cout << "Enter the second polynomial: \n";
        cin >> input2;
        Polinom p1(input1);
        Polinom p2(input2);

        printMenu();

        int choice = getIntInput("");

        cout << "\n" << endl;

        if (choice == 1) 
        {
            Polinom sum = p1 + p2;
            cout << "Sum: " << sum.toString() << endl;
        }

        else if (choice == 2) 
        {
            Polinom diff = p1 - p2;
            cout << "Difference: " << diff.toString() << endl;
        }

        else if (choice == 3) 
        {
            Polinom diff = p2 - p1;
            cout << "Difference: " << diff.toString() << endl;
        }

        else if (choice == 4) 
        {
            coef = getIntInput("Enter the coefficient: ");
            Polinom scaled = p1 * coef;
            cout << "Multiplying the first polynomial by " << coef << ": " << scaled.toString() << endl;
        }

        else if (choice == 5) 
        {
            var = getCharInput("Enter variable (x, y or z) to differentiate by: ");
			Polinom deriv = p1.derivative(var);
			cout << "Derivative of the first polynomial in " << var << ": " << deriv.toString() << endl;
        }

        else if (choice == 6) 
        {
            cout << "Exiting program.\n";
            break;
        }

        else {
            cout << "Invalid input. Please try again.\n";
        }
    }

    return 0;
}
