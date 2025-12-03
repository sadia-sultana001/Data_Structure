#include <iostream>

using namespace std;

class multiplyMat
{
public:
    void printMatrix(int mat[2][2], int r, int c)
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

    void multiply(int m1[2][2], int m2[2][2], int c[2][2], int r1, int c1, int r2, int c2)
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
};

int main()
{
    multiplyMat m;
    int A[2][2] = {{1, 2}, {7, 8}};
    int B[2][2] = {{2, 6}, {1, 9}};
    int C[2][2];
    int r1 = 2, c1 = 2, r2 = 2, c2 = 2;
    m.multiply(A, B, C, r1, c1, r2, c2);
    cout << "\n Resultant matrix:\n"
         << endl;
    m.printMatrix(C, r1, c2);
    return 0;
}