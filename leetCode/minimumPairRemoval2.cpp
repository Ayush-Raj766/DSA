#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    long long val;
    node* prev;
    node* next;
    bool isAlive;
    node(long long v){
        val = v;
        prev= nullptr;
        next = nullptr;
        isAlive =true; 
    }
};
int minimumPairRemoval(vector<int>& nums) {
    int n =  nums.size();
    if(n <=1){
        return 0;
    }

    vector<node>nodes;
    for(int i = 0 ; i < n ; i++){
        nodes.push_back(node(nums[i]));
    }
}


int main() {
    vector<int> nums ={7, 3, 5, 2, 6, 1, 4, 3, 8};
    cout<< minimumPairRemoval(nums)<<endl;
    
    return 0;
}