#include<bits/stdc++.h>
using namespace std;

class DSU{
    vector<int> parent , rank;
public:
    DSU(int n){
        parent.resize(n);
        rank.resize(n , 0);
        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
    }

    bool unionByRank(int u , int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return false;

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
        return true;
    }
};

class Solution{
public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators){
        DSU dsu(n*m);
        vector<int> ans;
        int count = 0;

        vector<vector<int>> vis(n , vector<int>(m, 0));

        for(auto it : operators){
            int row = it[0];
            int col = it[1];

            if(vis[row][col] == 1){
                ans.push_back(count);
                continue;
            }

            vis[row][col]= 1;
            count++;

            int node = row*m + col;

            int delRow[] = {-1 , 0 , +1 , 0};
            int delCol[] = {0 , +1 , 0 , -1};

            for(int i = 0 ; i < 4 ; i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && vis[nRow][nCol] == 1){
                    int adjNode = nRow*m + nCol;
                    if(dsu.unionByRank(node, adjNode)){
                        count--;
                    }
                }
            }

            ans.push_back(count);
        }
        return ans;
    }
};

int main() {
    int n = 4, m = 5;
    vector<vector<int>> operators = {
        {0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1},
        {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2},
        {1, 2}, {0, 2}
    };

    Solution obj;
    vector<int> ans = obj.numOfIslands(n, m, operators);

    for (auto res : ans) cout << res << " ";
    cout << endl;

    return 0;
}