#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
       int  totalsum = accumulate(values.begin(), values.end(), 0);
        if (totalsum % k == 0) {
            if(node)
            
        };
    }

int main() {
     int n = 6;
    vector<vector<int>> edges = {{0,1},{0,2},{1,3},{1,4},{2,5}};
    vector<int> values = {2,1,1,1,1,2};
    int k = 2;

    Solution s;
    cout << s.maxKDivisibleComponents(n, edges, values, k);
    return 0;
}