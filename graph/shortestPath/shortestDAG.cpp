#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void topoSort(int node , vector<pair<int , int>> adj[] ,  int vis[] , stack<int> &st){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it.first]){
                topoSort(it.first , adj , vis , st);
            }
        }
        st.push(node);
    }

    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        vector<pair<int , int>> adj[N];
        for(auto it : edges){
            adj[it[0]].push_back({it[1] , it[2]});
        }
        int vis[N];
        for(int i = 0; i < N; i++){
            vis[i] = 0;
        }
        stack<int> st;
        for(int i = 0; i < N; i++){
            if(!vis[i]){
                topoSort(i , adj , vis , st);
            }
        }
        vector<int> dist(N , 1e9);
        dist[0] = 0;

        while(!st.empty()){
            int node = st.top();
            st.pop();

            for(auto it : adj[node]){
                if(dist[node] + it.second < dist[it.first]){
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
        return dist;
    }
};

int main() {
     // Number of nodes and edges
  int N = 6, M = 7;

  // Edge list input
  vector<vector<int>> edges = {
    {0, 1, 2},
    {0, 4, 1},
    {4, 5, 4},
    {4, 2, 2},
    {1, 2, 3},
    {2, 3, 6},
    {5, 3, 1}
  };

  // Create object of Solution class
  Solution obj;

  // Call shortestPath function
  vector<int> ans = obj.shortestPath(N, M, edges);

  // Print the resulting shortest distances
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
    return 0;
}