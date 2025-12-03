#include <iostream>

using namespace std;

void sort(int array[], int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] < array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter size of array:";
    cin >> n;

    int arr[n];
    cout << "Enter elements of this array :";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    //  int size = sizeof(arr) / sizeof(arr[0]);
    sort(arr, n);
    cout << "Decending Order : ";
    for (int x : arr)
    {
        std::cout << x << "  ";
    }
}