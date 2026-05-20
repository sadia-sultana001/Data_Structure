#include <bits/stdc++.h>
#include <ctype.h>

using namespace std;

int pre(char ch)
{
  if (ch == '+')
    return 1;
  else if (ch == '-')
    return 1;
  else if (ch == '*')
    return 2;
  else
    return 2;
}

int solve(int v1, int v2, char ch)
{
  if (ch == '+')
    return v1 + v2;
  else if (ch == '-')
    return v1 - v2;
  else if (ch == '*')
    return v1 * v2;
  else
    return v1 / v2;
}

int main()
{
  string str;
  getline(cin, str);
  stack<int> is;
  stack<char> op;
  for (int i = 0; i < str.length(); i++)
  {
    char ch = str[i];
    if (isdigit(ch))
    {
      is.push(ch - '0');
    }
    else if (ch == '(')
    {
      op.push(ch);
    }
    else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
      while (op.size() > 0 && (op.top() != '(' && pre(ch) <= pre(op.top())))
      {
        int v2 = is.top();
        is.pop();
        int v1 = is.top();
        is.pop();
        int op1 = op.top();
        op.pop();
        int ans = solve(v1, v2, op1);
        is.push(ans);
      }
      op.push(ch);
    }

    else if (ch == ')')
    {
      while (op.size() > 0 && op.top() != '(')
      {
        int v2 = is.top();
        is.pop();
        int v1 = is.top();
        is.pop();
        int op1 = op.top();
        op.pop();
        int ans = solve(v1, v2, op1);
        is.push(ans);
      }
      if (op.size() > 0)
      {
        op.pop();
      }
    }
  }
  while (op.size() > 0)
  {
    int v2 = is.top();
    is.pop();
    int v1 = is.top();
    is.pop();
    int op1 = op.top();
    op.pop();
    int ans = solve(v1, v2, op1);
    is.push(ans);
  }
  int ans = is.top();
  is.pop();
  cout << ans << endl;
}
