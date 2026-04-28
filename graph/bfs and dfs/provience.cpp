#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void bfs(vector<int> adj[], int start , vector<int>& vis) {
        queue<int> q;
        q.push(start);
        vis[start] = 1 ;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

    }

    int numProvinces(vector<vector<int>>& adj , int V){
        vector<int> adjlist[V];
        for(int i = 0 ; i < V  ; i++){
            for(int j = 0 ; j < V  ;j++){
                if(adj[i][j] == 1 && i!=j){
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        vector<int> vis(V,0);
        int count = 0;
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                bfs(adjlist, i , vis);
                count++;
            }
        }
        return count;
    }
};

int main() {
     vector<vector<int>> adj = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    // Number of vertices
    int V = 3;

    // Create object of Solution
    Solution obj;

    // Call the function and print result
    cout << obj.numProvinces(adj, V) << endl;

    return 0;
}