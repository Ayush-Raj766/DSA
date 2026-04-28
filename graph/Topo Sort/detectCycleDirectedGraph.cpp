#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool checkCycle(int node , vector<vector<int>>& adj ,  vector<int>& vis , vector<int>& dfsvis) {
    vis[node] = 1;
    dfsvis[node] = 1 ; 
    for(auto it : adj[node]){
        if(!vis[it]){
            if(checkCycle(it , adj , vis , dfsvis)){
                return true;
            }
            else if(dfsvis[it]){
                return true;
            }
        }
    }
    dfsvis[node] = 0;
    return false;
}


    bool hasCycle(int V, vector<vector<int>>& adj) {
        vector<int> vis(V, 0);
        vector<int>dfsvis(V, 0);
        for(int i = 0 ; i  < V ; i++ ){
            if(!vis[i]){
                if(checkCycle(i, adj, vis, dfsvis)){
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    int V = 4;
    vector<vector<int>> adj = {
        {1}, {2}, {3}, {1}
    };

    Solution obj;
    if (obj.hasCycle(V, adj))
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";
    return 0;
    return 0;
}