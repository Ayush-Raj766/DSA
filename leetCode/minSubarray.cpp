#include<bits/stdc++.h>
using namespace std;

int minSubarray(vector<int> &num , int p){
    int n  = num.size();
    long long sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum += num[i];
    }
    int target = sum % p;
    if(target == 0) return 0;
    unordered_map<int , int> modIndex;
    modIndex[0] = -1;
    long long currMod = 0;
    int minLength = n;
    for(int i = 0 ; i < n ; i++){
        currMod = (currMod + num[i]) % p;
        int desiredMod = (currMod - target + p) % p;
        if(modIndex.find(desiredMod) != modIndex.end()){
            minLength = min(minLength , i - modIndex[desiredMod]);
        }
        modIndex[currMod] = i;
    }
    return minLength == n ? -1 : minLength;
}

int main() {
    vector<int> nums = { 4 , 6 , 7 ,9 ,2 , 15 ,1 ,7};
    int p = 9;
    minSubarray(nums , p);
    return 0;
}