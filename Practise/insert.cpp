#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "ENTER THE SIZE OF ARRAY: ";
    cin >> n;

    int a[n];
    int key, temp;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++)
    {

        temp = a[i];
        key = i - 1;

        while (key >= 0 && temp < a[key])
        {
            a[key + 1] = a[key];
            key--;
        }
        a[key + 1] = temp;
    }
}