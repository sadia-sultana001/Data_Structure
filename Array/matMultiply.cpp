#include <iostream>

using namespace std;

void readMatrix(int mat[10][10], int r, int c)
{
    cout << "Enter elements : \n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> mat[i][j];
        }
    }
}

void printMatrix(int mat[10][10], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void multiply(int m1[10][10], int m2[10][10], int c[10][10], int r1, int c1, int r2, int c2)
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            c[i][j] = 0;
        }
    }

    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < c1; k++)
            {
                c[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

int main()
{
    int mat1[10][10], mat2[10][10], res[10][10];
    int r1, r2, c1, c2;

    cout << "Enter rows and colomn of Martix-1 :";
    cin >> r1 >> c1;
    cout << "Enter rows and colomn of Martix-2 :";
    cin >> r2 >> c2;

    if (c1 != r2)
    {
        cout << "Matrix multiplication is not possible.";
    }
    cout << "\nMatrix-1:\n";
    readMatrix(mat1, r1, c1);

    cout << "\nMatrix-2:\n";
    readMatrix(mat2, r2, c2);

    multiply(mat1, mat2, res, r1, c1, r2, c2);

    cout << "\n Resultant matrix:\n"
         << endl;
    printMatrix(res, r1, c2);
    return 0;
}