#include<iostream>
using namespace std;

long long fact (int n)
{
      if(n == 0)
            return 0;
      if(n == 1)
            return 1;
      return n * fact(n -1);
}

int main()
{
      int n, r;
      cin >> n >> r;

      if(r > n)
      {
            cout<< "Invalid input";
      return 0;
      }
      long long nPr = fact(n)/ (fact(r)* fact(n- r));
      cout << nPr;
      return 0;
}






