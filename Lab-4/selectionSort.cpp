#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int arr[N], temp;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";

    return 0;
}