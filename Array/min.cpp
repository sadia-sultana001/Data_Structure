#include <iostream>

using namespace std;

int main()
{
    int n;
    int min = 0;
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
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    cout << "Maximum element is :" << min << endl;
}