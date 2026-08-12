#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> medians;
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int i = 0 ; i<n ; i++){
            
        }
        
        
    }
};



int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    Solution solution;
    vector<double> result = solution.medianSlidingWindow(nums, k);
    for (double median : result) {
        cout << median << " ";
    }
    
    return 0;
}