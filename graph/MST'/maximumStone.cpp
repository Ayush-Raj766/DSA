#include<bits/stdc++.h>
using namespace std;
class DSU{
    vector<int> parent , rank;
    public:
    DSU(int n){
        parent.resize(n+1 );
        rank.resize(n+1 , 0);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }
    int findUPar(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u , int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0 , maxCol = 0;
        for(int i = 0; i < n; i++){
            maxRow = max(maxRow , stones[i][0]);
            maxCol = max(maxCol , stones[i][1]);
        }
        DSU dsu(maxRow + maxCol + 1);
        unordered_set<int> mp;
        for(auto it : stones){
            int row = it[0];
            int col = it[1] + maxRow + 1;
            dsu.unionByRank(row , col);
            mp.insert(row);
            mp.insert(col);
        }
        int cnt = 0;
        for(auto it : mp){
            if(dsu.findUPar(it) == it) cnt++;
        }
        return n - cnt;


    }
};

int main() {
     vector<vector<int>> stones = {
        {0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}
    };

    Solution obj;
    cout << obj.removeStones(stones) << endl;
    return 0;
}