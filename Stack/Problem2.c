#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int operandStack[MAX], topOperand = -1;
char operatorStack[MAX]; int topOperator = -1;

void pushOperand(int x) { operandStack[++topOperand] = x; }
int popOperand() { return operandStack[topOperand--]; }
void pushOperator(char x) { operatorStack[++topOperator] = x; }
char popOperator() { return operatorStack[topOperator--]; }
char peekOperator() { return operatorStack[topOperator]; }

int precedence(char op){
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    return 0;
}

int applyOp(int a, int b, char op){
    switch(op){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
    }
    return 0;
}

int evaluate(char* expr){
    int i=0;
    while(expr[i]){
        if(isspace(expr[i])) { i++; continue; }

        if(isdigit(expr[i])){
            int val = 0;
            while(isdigit(expr[i])){
                val = val*10 + (expr[i]-'0');
                i++;
            }
            pushOperand(val);
        }
        else if(expr[i]=='('){
            pushOperator(expr[i]);
            i++;
        }
        else if(expr[i]==')'){
            while(topOperator!=-1 && peekOperator()!='('){
                int val2 = popOperand();
                int val1 = popOperand();
                char op = popOperator();
                pushOperand(applyOp(val1,val2,op));
            }
            popOperator(); // remove '('
            i++;
        }
        else { // operator
            while(topOperator!=-1 && precedence(peekOperator())>=precedence(expr[i])){
                int val2 = popOperand();
                int val1 = popOperand();
                char op = popOperator();
                pushOperand(applyOp(val1,val2,op));
            }
            pushOperator(expr[i]);
            i++;
        }
    }

    while(topOperator!=-1){
        int val2 = popOperand();
        int val1 = popOperand();
        char op = popOperator();
        pushOperand(applyOp(val1,val2,op));
    }

    return popOperand();
}

int main(){
    char expr[100];
    printf("Enter infix expression: ");
    fgets(expr, 100, stdin);
    expr[strcspn(expr, "\n")] = 0; // remove newline
    printf("Result: %d\n", evaluate(expr));
    return 0;
}
