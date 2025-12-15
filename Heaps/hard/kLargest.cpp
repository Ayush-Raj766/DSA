#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    priority_queue<int , vector<int> , greater<int>>minheap;
    int size;

    Solution(int n , vector<int>& nums){
        size = n;
        for(auto k : nums){
            minheap.push(k);
             if(minheap.size() > size){
            minheap.pop();
        }
        }
    }

    int add (int n){
        minheap.push(n);

        if(minheap.size() > size){
            minheap.pop();
        }

        return minheap.top();
    }

};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    Solution kthLargest(3, nums);
    cout << kthLargest.add(3) << endl;  // Output: 4
    cout << kthLargest.add(5) << endl;  // Output: 5
    cout << kthLargest.add(10) << endl; // Output: 5
    cout << kthLargest.add(9) << endl;  // Output: 8
    cout << kthLargest.add(4) << endl;  // Output: 8
    return 0;
    return 0;
}