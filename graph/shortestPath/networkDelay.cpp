#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int , int>> adj[n+1];
        for(auto it : times){
            adj[it[0]].push_back({it[1] , it[2]});
        }
        vector<int> dist(n+1 , 1e9);
        dist[k] = 0;
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
        pq.push({0 , k});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int time = it.first;
            for(auto it : adj[node]){
                int adjNode = it.first;
                int edw = it.second;
                if(time + edw < dist[adjNode]){
                    dist[adjNode] = time + edw;
                    pq.push({time + edw , adjNode});
                }
            }
        }
        int maxDelay = 0;
        for(int i = 1; i <= n; i++){
            maxDelay = max(maxDelay , dist[i]);
        }
        return maxDelay == 1e9 ? -1 : maxDelay;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4, k = 2;
    cout << sol.networkDelayTime(times, n, k) << endl;
    return 0;
}