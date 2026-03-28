#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        stack[++top] = ch;
    }
}

// Pop function
char pop() {
    if (top == -1) {
        return '\0'; // empty stack
    } else {
        return stack[top--];
    }
}

// Function to check matching pairs
int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

int main() {
    char expr[MAX];
    
    printf("Enter Expression: ");
    scanf("%s", expr);

    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];

        // If opening bracket → push
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        // If closing bracket → check
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1) {
                printf("Not Balanced Expression\n");
                return 0;
            }

            char popped = pop();

            if (!isMatchingPair(popped, ch)) {
                printf("Not Balanced Expression\n");
                return 0;
            }
        }
    }

    // Final check
    if (top == -1)
        printf("Balanced Expression\n");
    else
        printf("Not Balanced Expression\n");

    return 0;
}