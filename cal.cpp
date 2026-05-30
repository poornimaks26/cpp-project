#include <iostream>
#include <limits>
#include <string>

using namespace std;

class Calculator {
public:
    double calculate(double a, char op, double b, bool& hasError, string& errorMsg) {
        hasError = false;
        errorMsg = "";
        
        switch (op) {
            case '+': return a + b;

            case '-': return a - b;
            case '*': return a * b;
            case '/':
                if (b == 0) {
                    hasError = true;
                    errorMsg = "Division by zero is mathematically undefined.";
                    return 0;
                }
                return a / b;
            default:
                hasError = true;
                errorMsg = "Unknown or unsupported operator.";
                return 0;
        }
    }
};

// Helper function to safely get a number from user input
double getNumber(const string& prompt) {
    double num;
    while (true) {
        cout << prompt;
        if (cin >> num) {
            return num;
        } else {
            cout << "❌ Invalid input. Please enter a valid number (decimals are allowed).\n";
            cin.clear(); // Clear the error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
        }
    }
}

// Helper function to safely get a valid operator
char getOperator() {
    char op;
    while (true) {
        cout << "Enter an operator (+, -, *, /): ";
        cin >> op;
        if (op == '+' || op == '-' || op == '*' || op == '/') {
            return op;
        } else {
            cout << "❌ Invalid operator! Try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int main() {
    Calculator calc;
    char choice;

    cout << "=====================================================\n";
    cout << "             ROBUST INTERACTIVE CALCULATOR           \n";
    cout << "=====================================================\n";

    do {
        // 1. Get safe inputs from the user
        double num1 = getNumber("Enter the first number: ");
        char op = getOperator();
        double num2 = getNumber("Enter the second number: ");

        // 2. Process computation and check for errors
        bool hasError = false;
        string errorMsg = "";
        double result = calc.calculate(num1, op, num2, hasError, errorMsg);

        // 3. Display Result or Error Status
        cout << "-----------------------------------------------------\n";
        if (hasError) {
        cout << "⚠️  ERROR: " << errorMsg << "\n";
        } else {
            cout << "✅"<< "RESULT: " << num1 << " " << op << " " << num2 << " = " << result << "\n";
        }
        cout << "-----------------------------------------------------\n";

        // 4. Prompt to continue
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> choice;
        cout << "\n";

    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for using the calculator. Goodbye!\n";
    return 0;
}