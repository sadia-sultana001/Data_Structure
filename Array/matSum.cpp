#include <iostream>

using namespace std;

int main()
{
    int R, C;
    cout << "Enter row size of matrix:";
    cin >> R;
    cout << "Enter colomn size of matrix:";
    cin >> C;
    int mat1[R][C], mat2[R][C];
    int res[R][C];
    cout << "Enter the element of matrix-1:\n";
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> mat1[i][j];
        }
    }
    cout << endl;
    cout << "Enter the element of matrix-2:\n";
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> mat2[i][j];
        }
    }
    cout << endl
         << "Sum of Two matrices:\n";
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            res[i][j] = mat1[i][j] + mat2[i][j];
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}