#include <stdio.h>
#define MAX 100
int stack[MAX];
int top = -1;
void push(int x)
{
    stack[++top] = x;
}
int pop()
{
    return stack[top--];
}
int peek()
{
    return stack[top];
}
int isEmpty()
{
    return top == -1;
}
void findNGE(int arr[], int n)
{
    int res[MAX];
    for (int i = n - 1; i >= 0; i--)
    {
        while (!isEmpty() && peek() <= arr[i])
        {
            pop();
        }
        res[i] = isEmpty() ? -1 : peek();
        push(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d -> %d\n", arr[i], res[i]);
    }
}
int main()
{
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    findNGE(arr, n);
    return 0;
}
