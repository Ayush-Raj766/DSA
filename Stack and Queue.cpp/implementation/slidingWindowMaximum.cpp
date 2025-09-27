#include <bits/stdc++.h>
using namespace std;

void getMax(int l ,  int r, vector<int> &res ,vector<int> &arr){
    int maxi= INT_MIN;
    for(int i =l ;i<=r ;i++){
        maxi = max(maxi , arr[i]);
    }
    res.push_back(maxi);

}

vector <int> maxSlidingWindow(vector <int> &arr , int k){
    int left =0;
    int right =0;
    vector <int> res;
    while (right < k-1){
        right++;
    }
    while(right < arr.size()){
        getMax(left , right , res , arr);
        left++;
        right++;
    }
    return res;

}

int main()
{
    int i, j, n, k = 3, x;
    vector<int> arr{
        4, 0,
        -1,
        3,
        5,
        3,
        6,
        8};
    vector<int> ans;
    ans = maxSlidingWindow(arr, k);
    cout << "Maximum element in every " << k << " window " << endl;
    for (i = 0; i < ans.size(); i++)
        cout << ans[i] << "  ";
    return 0;
}