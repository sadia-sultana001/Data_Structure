#include <iostream>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;

    int adj[100][100] = {0};

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u][v] = 1;
        adj[v][u] = 1; // undirected
    }

    // print matrix
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}