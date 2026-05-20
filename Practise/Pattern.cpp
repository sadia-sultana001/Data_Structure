#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> buildLPS(string pattern)
{
    int m = pattern.length();
    vector<int> lps(m, 0);

    int len = 0;
    int i = 1;

    while (i < m)
    {
        if (pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

int KMP(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();

    vector<int> lps = buildLPS(pattern);

    int i = 0;
    int j = 0;

    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            return i - j;
        }

        else if (i < n && text[i] != pattern[j])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    return -1;
}

int main()
{
    string text, pattern;

    cout << "Enter Text: ";
    cin >> text;

    cout << "Enter Pattern: ";
    cin >> pattern;

    int index = KMP(text, pattern);

    if (index == -1)
        cout << "Pattern not found" << endl;
    else
        cout << "Pattern found at index: " << index << endl;

    return 0;
}
