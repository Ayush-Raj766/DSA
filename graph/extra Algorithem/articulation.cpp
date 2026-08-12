#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, int &time, vector<int> &disc, vector<int> &low, vector<int> &parent, vector<int> &ap, vector<int> adj[])
    {
        disc[node] = low[node] = time++;
        int children = 0;
        for (auto it : adj[node])
        {
            if (disc[it] == -1)
            {
                children++;
                parent[it] = node;
                dfs(it, time, disc, low, parent, ap, adj);
                low[node] = min(low[node], low[it]);
                if (parent[node] == -1 && children > 1)
                {
                    ap[node] = 1;
                }
                if (parent[node] != -1 && low[it] >= disc[node])
                {
                    ap[node] = 1;
                }
            }
            else if (it != parent[node])
            {
                low[node] = min(low[node], disc[it]);
            }
        }
    }

public:
    vector<int> articulationPoints(int v, vector<int> adj[])
    {
        vector<int> disc(v, -1);
        vector<int> low(v, -1);
        vector<int> parent(v, -1);
        vector<int> ap(v, 0);
        int time = 0;
        for (int i = 0; i < v; i++)
        {
            if (disc[i] == -1)
            {
                dfs(i, time, disc, low, parent, ap, adj);
            }
        }
        vector<int> res;
        for (int i = 0; i < v; i++)
        {
            if (ap[i] == 1)
            {
                res.push_back(i);
            }
        }
        if (res.size() == 0)
        {
            return {-1};
        }
        return res;
    }
};

int main()
{
    int n = 6;
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {3, 4}, {3, 5}};

    vector<int> adj[n];
    for (auto e : edges)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    Solution sol;
    vector<int> res = sol.articulationPoints(n, adj);
    for (int v : res)
        cout << v << " ";
    cout << endl;
    return 0;
}