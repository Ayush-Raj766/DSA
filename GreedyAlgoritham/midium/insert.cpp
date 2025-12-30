class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();
        int i = 0;

        while( i < n && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }

        while(i<n && intervals[i][0] < newInterval[1]){
            newInterval[0] = min(newInterval[0] , intervals[i][0]);
            newInterval[1] = min(newInterval[1] , intervals[i][1]);
            i++;
        }
        res.push_back(newInterval);

        while(i<n){
            res.push_back(intervals[i]);
        }
        return res;
    }
};

#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> newInterval = {4,8};
    Solution ob;
    ob.insert (intervals , newInterval);
    
    return 0;
}