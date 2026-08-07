#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

#define MAX 100

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top == MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int evaluatePrefix(string exp) {
    Stack s;

    for (int i = exp.length() - 1; i >= 0; i--) {
        char ch = exp[i];

        // Ignore spaces
        if (ch == ' ')
            continue;

        // If operand (single digit)
        if (isdigit(ch)) {
            s.push(ch - '0');
        }
        else {
            int op1 = s.pop();
            int op2 = s.pop();
            int result;

            switch (ch) {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
                case '^':
                    result = pow(op1, op2);
                    break;
                default:
                    cout << "Invalid Operator\n";
                    return -1;
            }

            s.push(result);
        }
    }

    return s.pop();
}

int main() {
    string prefix;

    cout << "Enter Prefix Expression: ";
    cin >> prefix;

    cout << "Result = " << evaluatePrefix(prefix) << endl;

    return 0;
}