#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
void bfs(vector<vector<int>>& image , int sr , int sc , int newColor , vector<vector<int>>& vis , int oc){
    int rows = image.size();
    int cols = image[0].size();
    queue<pair<int,int>> q;
    q.push({sr,sc});
    vis[sr][sc] = 1;
    image[sr][sc] =newColor;
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i = 0 ; i<4 ; i++){
            int nrow = r + dr[i];
            int ncol = c + dc[i];
            if(nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols && vis[nrow][ncol] == 0 && image[nrow][ncol] == oc){
                vis[nrow][ncol] = 1;
                image[nrow][ncol] = newColor;
                q.push({nrow,ncol});
            }
        }
    }
}


vector<vector<int>> floodFill(vector<vector<int>>& image , int sr , int sc , int newColor){
    int rows = image.size();
    int cols = image[0].size();
    int oc = image[sr][sc];
    vector<vector<int>> vis(rows , vector<int>(cols , 0));
    bfs(image , sr , sc , newColor , vis , oc);
    return image;
}
};

int main() {
    vector<vector<int>>image{
	    {1,1,1},
	    {1,1,0},
	    {1,0,1}
	};
	
// sr = 1, sc = 1, newColor = 2  	
	Solution obj;
	vector<vector<int>> ans = obj.floodFill(image, 1, 1, 2);
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
    return 0;
}