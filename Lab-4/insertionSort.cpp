#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int arr[N], temp, ptr;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int k = 1; k < N; k++)
    {
        temp = arr[k];
        ptr = k - 1;

        while (ptr >= 0 && temp < arr[ptr])
        {
            arr[ptr + 1] = arr[ptr];
            ptr--;
        }
        arr[ptr + 1] = temp;
    }

    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";

    return 0;
}
