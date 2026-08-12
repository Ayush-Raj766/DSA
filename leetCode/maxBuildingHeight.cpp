#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        sort(restrictions.begin(), restrictions.end());
        

    }
};
int main() {
    int n = 10;
    vector<vector<int>> restrictions = {{5,3},{2,5},{7,4},{10,3}};
    Solution sol;
    cout << sol.maxBuilding(n, restrictions) << endl;

    return 0;
}