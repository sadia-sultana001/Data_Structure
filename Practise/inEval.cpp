#include <bits/stdc++.h>
#include <cctype>
using namespace std;

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;

    return 0;
}

int applyOperation(int a, int b, int op)
{
    if (op == '+')
        return a + b;

    if (op == '-')
        return a - b;

    if (op == '*')
        return a * b;

    if (op == '/')
        return a / b;

    return 0;
}

int evaluate(string exp)
{
    stack<int> values;
    stack<char> ops;

    for (int i = 0; i < exp.length(); i++)
    {

        if (exp[i] == ' ')
            continue;

        if (isdigit(exp[i]))
        {
            int val = 0;

            while (i < exp.length() && isdigit(exp[i]))
            {
                val = val * 10 + (exp[i] - '0');
                i++;
            }

            values.push(val);
        }

        else if (exp[i] == '(')
        {
            ops.push(exp[i]);
        }

        else if (exp[i] == ')')
        {
            while (ops.top() != '(')
            {
                int b = values.top();
                values.pop();

                int a = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOperation(a, b, op));
            }
            ops.pop();
        }
        else
        {
            while (!ops.empty() && precedence(ops.top()) >= precedence(exp[i]))
            {
                int b = values.top();
                values.pop();

                int a = values.top();
                values.pop();

                char op = ops.top();
                ops.pop();

                values.push(applyOperation(a, b, op));
            }

            ops.push(exp[i]);
        }
    }

    while (!ops.empty())
    {
        int b = values.top();
        values.pop();

        int a = values.top();
        values.pop();

        char op = ops.top();
        ops.pop();

        values.push(applyOperation(a, b, op));
    }
    return values.top();
}

int main()
{

    string exp;
    cout << "Enter expresions:";
    getline(cin, exp);

    cout << "RESULT: " << evaluate(exp);

    return 0;
}