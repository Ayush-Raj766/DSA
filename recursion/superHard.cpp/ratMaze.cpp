#include<bits/stdc++.h>
using namespace std;


class Solution{
    public: 

    bool isSafe(int x , int y , int n , vector<vector<int>> &m, vector<vector<int>> &vis){
        if(x>=0 && x<n && y>=0 && y<n && vis[x][y] == 0 && m[x][y]==1){
            return true;
        }
        return false;
    }
    void solve(int x, int y, int n, vector<vector<int>> &m, 
           vector<vector<int>> &vis, string path, vector<string> &ans){
            if(x==n-1 && y==n-1){
                ans.push_back(path);
                return;
            }
            vis[x][y]=1;

            if(isSafe(x+1,y,n,m, vis)){
                solve(x+1,y,n,m,vis,path+"D",ans);
            }
            if(isSafe(x-1,y,n,m, vis)){
                solve(x-1,y,n,m,vis,path+"U",ans);
            }
            if(isSafe(x,y+1,n,m, vis)){
                solve(x,y+1,n,m,vis,path+"R",ans);
            }
            if(isSafe(x,y-1,n,m, vis)){
                solve(x,y-1,n,m,vis,path+"L",ans);
            }

            vis[x][y]=0;

    

    }
    vector<string>findPath(vector<vector<int>> &m , int n){
        vector<string> ans;
        vector < vector < int >> vis(n, vector < int > (n, 0));

      if (m[0][0] == 1) solve(0, 0, n, m, vis, "", ans);
      return ans;
    }
};

int main() {
    int n = 4;

   vector < vector < int >> m = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};

  Solution obj;
  vector < string > result = obj.findPath(m, n);
  if (result.size() == 0)
    cout << -1;
  else
    for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
  cout << endl;

  return 0;
}