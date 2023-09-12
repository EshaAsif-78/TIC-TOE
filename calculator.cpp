#include <iostream>
using namespace std;
int main() {
    double num1, num2;
    double result;
    char operation;

    cout << "Simple Calculator" << endl;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter an operation (+, -, *, /): ";
    cin >> operation;
    cout << "Enter the second number: ";
    cin >> num2;
    bool validOperation = true;
    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
            cout << "Error: Division by zero is not allowed." <<endl;
                validOperation = false;
            }
            break;
        default:
            cout << "Invalid operation." << std::endl;
            validOperation = false;
    }

    if (validOperation) {
    cout << "Result: " << num1 << " " << operation << " " << num2 << " = " << result << endl;
    }

    return 0;
}

