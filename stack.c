#include <stdio.h>
#include <ctype.h>

int stack[100];
int top = -1;

// Push function
void push(int x) {
    stack[++top] = x;
}

// Pop function
int pop() {
    return stack[top--];
}

int main() {
    char exp[100];
    printf("Enter postfix expression (e.g., 23+): ");
    scanf("%s", exp);

    for (int i = 0; exp[i] != '\0'; i++) {
        // If digit, push to stack
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } 
        // If operator, pop 2 numbers and calculate
        else {
            int val2 = pop();
            int val1 = pop();

            if (exp[i] == '+') push(val1 + val2);
            else if (exp[i] == '-') push(val1 - val2);
            else if (exp[i] == '*') push(val1 * val2);
            else if (exp[i] == '/') push(val1 / val2);
        }
    }

    printf("Result = %d\n", pop());
    return 0;
}