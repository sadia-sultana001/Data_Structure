#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Stack functions for operators
void push(char x) { stack[++top] = x; }
char pop() { return stack[top--]; }
char peek() { return top == -1 ? '\0' : stack[top]; }

int prec(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

// Infix to Postfix conversion
void infixToPostfix(char infix[], char postfix[]) {
    int k = 0;
    top = -1; // reset stack

    for (int i = 0; infix[i]; i++) {
        char ch = infix[i];

        if (isdigit(ch)) {
            postfix[k++] = ch; // operand goes to output
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top != -1 && peek() != '(')
                postfix[k++] = pop();
            pop(); // remove '('
        } else { // operator
            while (top != -1 && prec(peek()) >= prec(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }

    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';
}

// Evaluate postfix expression
int evalPostfix(char postfix[]) {
    int st[100], top_eval = -1;

    for (int i = 0; postfix[i]; i++) {
        if (isdigit(postfix[i])) {
            st[++top_eval] = postfix[i] - '0';
        } else {
            int b = st[top_eval--];
            int a = st[top_eval--];
            switch(postfix[i]) {
                case '+': st[++top_eval] = a + b; break;
                case '-': st[++top_eval] = a - b; break;
                case '*': st[++top_eval] = a * b; break;
                case '/': st[++top_eval] = a / b; break;
            }
        }
    }

    return st[top_eval];
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    int result = evalPostfix(postfix);

    printf("Postfix Notation = %s\n", postfix);
    printf("Postfix Result   = %d\n", result);

    return 0;
}
