#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int kthLargestElement(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int num : nums){
            minHeap.push(num);
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        return minHeap.top();
    }

    int kthSmallestElement(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<int>> maxHeap;
        for(int num : nums){
            maxHeap.push(num);
            if(maxHeap.size() > k){
                maxHeap.pop();
            }
        }
        return maxHeap.top();
    }
};

int main() {
    vector<int> nums = {-5, 4, 1, 2, -3};
    int k = 2;

    // Creating an object of the Solution class
    Solution sol;

    // Function call to get the Kth largest element 
    int ans = sol.kthLargestElement(nums, k);

    // Output array
    cout << "The Kth largest element in the array is: " << ans << endl;

    int ans2 = sol.kthSmallestElement(nums, k);
    cout << "The Kth smallest element in the array is: " << ans2 << endl;
    return 0;
}