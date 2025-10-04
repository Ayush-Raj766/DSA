#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:

    int totalFruit(vector <int> &num ){
    int l=0;
    int r=0;
    int limit =0;
    int count =0;
    int n = num.size();
    while(r<n){
        if(num[r] !=num[l]){
            limit++;
        }
        while(limit> 2){
            if(num[l]==num[r]){
                limit--;
            }
            l++;
        }
        count = max(count , r-l+1);
        r++;

    }
    return count;
}
};



int main() {
    Solution sol;
    vector<int> fruits = {1, 2, 3, 2, 2};
    cout << sol.totalFruit(fruits) << endl;
    return 0;
}