#include<bits/stdc++.h>
using namespace std;

vector<int> singleNumbers(vector<int> &nums){
    int result =0 ;
    for(int i = 0 ; i<nums.size() ; i++){
        result = result ^ nums[i];
    }
    int lastSet = ((result & (result-1)) ^ result);

    int x =0;
    int y = 0;

    for(int i = 0 ; i<nums.size() ; i++){
        if(lastSet & nums[i]){
            x =x^nums[i];
        }
        else{
            y = y^nums[i];
        }
    }
    if (x < y) return {x, y};
    else return {y, x};

}

int main() {
    vector<int> nums = {7, 1, 2, 1, 2, 5};
    vector<int> ans = singleNumbers(nums);

    cout << "Unique numbers: " << ans[0] << " " << ans[1] << endl;
    return 0;
}