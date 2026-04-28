#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n =  grid.size();
        int m = grid[0].size();
        vector<int> v;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){ 
                v.push_back(grid[i][j]);
            }   
        }
        for(int i = 0; i < v.size()-1; i++){
            if(v[i] % x != v[i+1] % x) return -1;
        }
        sort(v.begin(), v.end());
        int median = v[v.size()/2];
        int ans = 0;
        for(int i = 0; i < v.size(); i++){
            ans += abs(v[i] - median) / x;
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> grid = {{1,2,3},{4,5,6}};
    int x = 1;
    Solution sol;
    cout << sol.minOperations(grid, x) << endl;
    return 0;
}