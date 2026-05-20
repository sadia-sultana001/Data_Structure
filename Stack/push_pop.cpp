#include<iostream>

#define MAX 7
int stack[MAX];
int top = -1;

void push(int x){
    if(top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
        stack[++top] = x;
}
int pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

int main()
{
    push(12);
    push(4);
    push(5);
    push(1);
    push(19);

    printf("Pooped: %d\n", pop());
    printf("Pooped: %d\n", pop());

    printf("Pooped: %d\n", pop());

}