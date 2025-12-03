#include <iostream>

using namespace std;

int main()
{
    int n;
    int max = 0;
    cout << "Enter size of array:";
    cin >> n;

    int arr[n];
    cout << "Enter elements of this array :";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    cout << "Maximum element is :" << max << endl;
}