#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> &num){
    int n =num.size();
    vector<vector<int>> result;
    int total = (1<<n);
    for(int i = 0 ; i<total ; i++){
        vector<int> subSet;
        for(int j = 0 ; j<n ; j++){
            if(i & (1<<j)){
                subSet.push_back(num[j]);
            }
        }
        result.push_back(subSet);
    }
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = subsets(nums);

    cout << "All subsets:" << endl;
    for (auto& subset : ans) {
        cout << "[ ";
        for (int x : subset) cout << x << " ";
        cout << "]" << endl;
    }
    return 0;
}