#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void bfs(int row, int col, vector<vector<char>>& mat, vector<vector<int>>& vis, int n, int m){
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0 ; i < 4 ; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O'){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>>& mat){
        vector<vector<int>> vis(n , vector<int>(m,0));

        for(int i = 0 ; i < n ; i++){
            if(vis[i][0] == 0 && mat[i][0] == 'O'){
                bfs(i,0,mat,vis,n,m);
            }
            if(vis[i][m-1] == 0 && mat[i][m-1] == 'O'){
                bfs(i,m-1,mat,vis,n,m);
            }
        }

        for(int j = 0 ; j < m ; j++){
            if(vis[0][j] == 0 && mat[0][j] == 'O'){
                bfs(0,j,mat,vis,n,m);
            }
            if(vis[n-1][j] == 0 && mat[n-1][j] == 'O'){
                bfs(n-1,j,mat,vis,n,m);
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(vis[i][j] == 0 && mat[i][j] == 'O'){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;

    }
};

int main() {
    vector<vector<char>> mat{
        {'X','X','X','X'},
        {'X','O','X','X'},
        {'X','O','O','X'},
        {'X','O','X','X'},
        {'X','X','O','O'}
    };
    // create solver
    Solution ob;
    // compute result
    vector<vector<char>> ans = ob.fill((int)mat.size(), (int)mat[0].size(), mat);
    // print board
    for (int i = 0; i < (int)ans.size(); i++) {
        for (int j = 0; j < (int)ans[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}