#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> graph[100];
bool visited[100];

void dfs(int start)
{
    stack<int> st;

    st.push(start);

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (visited[node])
        {
            continue;
        }

        visited[node] = true;

        cout << node << " ";

        for (int neighbor : graph[node])
        {
            if (!visited[neighbor])
            {
                st.push(neighbor);
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cin >> start;

    dfs(start);

    return 0;
}