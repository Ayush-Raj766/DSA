#include<bits/stdc++.h>
using namespace std;

class DisjointSet
{
    public:
    vector<int> rank, parent ;
    DisjointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUpar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUpar(parent[node]);
    }

    void unite(int u , int v){
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if(ulp_v == ulp_u) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        DisjointSet ds(n);

        for(auto it : connections){
            ds.unite(it[0], it[1]);
        }

        unordered_set<int> s;
        for(int i = 0; i < n; i++){
            s.insert(ds.findUpar(i));
        }
        return s.size() - 1;
        
        
    }
};

int main() {
    int n = 6;
    vector<vector<int>> connections = {{0,1},{0,2},{0,3},{1,4}};
    Solution sol;
    cout << sol.makeConnected(n, connections) << endl;
    return 0;
    return 0;
}