#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> maxCombinations(vector<int>& nums1, vector<int>& nums2, int k) {
        sort(nums1.begin() , nums1.end() , greater<int>());
        sort(nums2.begin() , nums2.end() , greater<int>());

        priority_queue<tuple<int , int , int>>maxheap;

        set<pair<int , int>>visted;

        maxheap.push({nums1[0] + nums2[0], 0, 0});
        
        visted.insert({0,0});

        vector<int>res;

        while(k-- > 0 && !maxheap.empty()){

            auto[sum , i ,j] = maxheap.top();
            maxheap.pop();

            res.push_back(sum);

            if(i+1<nums1.size() && !visted.count({i+1 , j})){
                maxheap.push({nums1[i+1] + nums2[j] , i+1 , j});
                visted.insert({i+1 , j});
            }

            if(j+1<nums2.size() && !visted.count({i , j+1})){
                maxheap.push({nums1[i] + nums2[j+1] , i , j+1});
                visted.insert({i , j+1});
            }
        }
        return res;
    }
};

int main() {
     Solution sol;
    vector<int> nums1 = {7, 3};
    vector<int> nums2 = {1, 6};
    int k = 2;
    vector<int> result = sol.maxCombinations(nums1, nums2, k);
    for(int val : result) cout << val << " ";
    return 0;
}