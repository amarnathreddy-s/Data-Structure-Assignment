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
        return '\0';
    } else {
        return stack[top--];
    }
}
int main() {
    char str[MAX];
    
    printf("Enter a string: ");
    scanf("%s", str);
    int len = strlen(str);
    // Push all characters into stack
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }
    // Pop all characters back into string (reversed)
    for (int i = 0; i < len; i++) {
        str[i] = pop();
    }
    printf("Reversed string: %s\n", str);
    return 0;
}

