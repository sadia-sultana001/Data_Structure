#include <iostream>

using namespace std;

int searchArr(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 8, 9, 3, 4, 99, 77, 43, 100, 22, 16, 76};
    int size = sizeof(arr) / sizeof(arr[0]);
    int index;
    int myNum;
    cout << "Enter element to search for: ";
    cin >> myNum;

    index = searchArr(arr, size, myNum);
    if (index != -1)
    {
        cout << myNum << " is at index : " << index;
    }
    else
    {
        cout << myNum << " is not in the array";
    }
    return 0;
}
