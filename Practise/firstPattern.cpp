#include <bits/stdc++.h>
#include <string>

using namespace std;

int main()
{
    string T, P;

    cout << "Enter text: ";
    cin >> T;

    cout << "Enter pattern: ";
    cin >> P;

    int S = T.length();
    int R = P.length();

    int MAX = S - R + 1;
    int INDEX = -1;

    for (int k = 0; k < MAX; k++)
    {
        int L;

        for (L = 0; L < R; L++)
        {
            if (P[L] != T[k + L])
            {
                break;
            }
        }
        if (L == R)
        {
            INDEX = k;
            break;
        }
    }

    if (INDEX != -1)
    {
        cout << "Pattern found at index: " << INDEX;
    }
    else
    {
        cout << "Pattern not found" << endl;
    }
    return 0;
}