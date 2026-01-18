#include<iostream>
using namespace std;

long long fib (int n)
{
      if(n == 0)
            return 0;
      if(n == 1)
            return 1;
      return fib(n -1) + fib(n - 2);
}

int main()
{
      int limit;
      cin >> limit;

      for(int i = 0;; i++)
      {
           long long value = fib(i);

           if (limit <= value)
              break;
          else
            cout<<fib(i) << " ";
      }
      return 0;
}


