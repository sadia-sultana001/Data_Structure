#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100


char stack[MAX];
int top = -1;

void push(char x) { stack[++top] = x; }
char pop() { return stack[top--]; }
char peek() { return top == -1 ? '\0' : stack[top]; }

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

void reverse(char s[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    int k = 0;
    top = -1; 

    for (int i = 0; infix[i]; i++) {
        char ch = infix[i];

        if (isdigit(ch)) {
            postfix[k++] = ch; 
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top != -1 && peek() != '(')
                postfix[k++] = pop();
            pop(); 
        } else { 
            while (top != -1 && precedence(peek()) >= precedence(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }

    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';
}

void infixToPrefix(char infix[], char prefix[]) {
    char revInfix[MAX], postfix[MAX];

    strcpy(revInfix, infix);
    reverse(revInfix);

 
    for (int i = 0; revInfix[i]; i++) {
        if (revInfix[i] == '(') revInfix[i] = ')';
        else if (revInfix[i] == ')') revInfix[i] = '(';
    }

    infixToPostfix(revInfix, postfix);
    reverse(postfix);
    strcpy(prefix, postfix);
}

int evalPrefix(char prefix[]) {
    int st[MAX], top_eval = -1;

    for (int i = strlen(prefix) - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (isdigit(ch)) {
            st[++top_eval] = ch - '0';
        } else {
            int left = st[top_eval--];
            int right = st[top_eval--];

            switch (ch) {
                case '+': st[++top_eval] = left + right; break;
                case '-': st[++top_eval] = left - right; break;
                case '*': st[++top_eval] = left * right; break;
                case '/': st[++top_eval] = left / right; break;
            }
        }
    }
    return st[top_eval];
}

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);
    int result = evalPrefix(prefix);

    printf("Prefix Notation = %s\n", prefix);
    printf("Prefix Result   = %d\n", result);

    return 0;
}
