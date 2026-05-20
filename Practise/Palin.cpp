#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

    string s;
    cin >> s;

    string rev = s;

    reverse(rev.begin(), rev.end());

    cout << "Original: " << s << endl;
    cout << "Reverse : " << rev << endl;

    if (s == rev)
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}