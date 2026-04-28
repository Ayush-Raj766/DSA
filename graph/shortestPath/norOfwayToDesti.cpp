#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int CheapestFLight(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        const int MOD = 1e9 + 7;

        vector<pair<int, int>> adj[n];
        for (auto &it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        dist[src] = 0;
        ways[src] = 1;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();

            for (auto &it : adj[node]) {
                int adjNode = it.first;
                long long wt = it.second;

                if (dis + wt < dist[adjNode]) {
                    dist[adjNode] = dis + wt;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                }
                else if (dis + wt == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1] % MOD;
        
    }
};

int main()
{
    int n = 7;

    // Define the edges (source, destination, weight)
    vector<vector<int>> edges = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};

    Solution obj;

    // Call the method to count the number of shortest paths
    int ans = obj.CheapestFLight(n, edges, 0, 3, 1);

    // Output the result
    cout << ans << endl;
    return 0;
}