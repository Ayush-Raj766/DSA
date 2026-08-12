#include<bits/stdc++.h>
using namespace std;

class DSU{
    vector<int> parent , rank , size;
    public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n , 0);
        size.resize(n , 1);
        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u , int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v]< rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;  
            
        }

    }
    void unionBySize(int u , int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    int getSize(int node){
        return size[node];
    }
};

class Solution{
    public:
   vector<int> delrow = {-1 , 0 , 1 , 0};
    vector<int> delcol = {0 , 1 , 0 , -1};

    int largest_Island(vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        DSU dsu(n*m);
        vector<vector<int>> vis(n , vector<int>(m, 0));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 0 ) continue;
                for(int k = 0 ; k < 4 ; k++){
                    int nrow = i + delrow[k];
                    int ncol = j + delcol[k];
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1){
                        int node = i*m + j;
                        int adjNode = nrow*m + ncol;
                        dsu.unionBySize(node , adjNode);
                    }
                }

            }
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 1) continue;
                int node = i*m + j;
                set<int> st;
                for(int k = 0 ; k < 4 ; k++){
                    int nrow = i + delrow[k];
                    int ncol = j + delcol[k];
                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1){
                        int adjNode = nrow*m + ncol;
                        st.insert(dsu.findUPar(adjNode));
                    }
                }
                int sizet = 0;
            for(auto it : st){
                sizet += dsu.getSize(it);
            }

            ans = max(ans , sizet + 1);
        }
    }

    // Step 3: Handle all-1 case
    for(int i = 0; i < n*m; i++){
        if(dsu.findUPar(i) == i){
            ans = max(ans, dsu.getSize(i));
        }
    }

    return ans;
}
};

int main() {
     vector<vector<int>> grid = {
        {1,0},
        {0,1}
    };

    // Creating instance of Solution class
    Solution sol;
    
    /* Function call to get the 
    size of the largest island */
    int ans = sol.largest_Island(grid);
    
    // Output
    cout << "The size of the largest island is: " << ans;
    
    return 0;
}