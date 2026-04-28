#include<bits/stdc++.h>
using namespace std;

bool compare(vector<int>&a , vector<int>&b){
    return a[2] < b[2];
}

vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin() ,  arr.end());
    vector<vector<int>>mindiff;

    for(int i = 1 ; i < n ; i++){
        mindiff.push_back({arr[i-1] , arr[i] , abs(arr[i-1] - arr[i])});
    }
    sort(mindiff.begin() , mindiff.end() , compare);

     vector<vector<int>> result;
    int minDiff = mindiff[0][2];

    for (auto &v : mindiff) {
        if (v[2] == minDiff) {
            result.push_back({v[0], v[1]});
        } else {
            break;
        }
    }

    return result;

}

int main() {
    vector<int> arr = {3,8,-10,23,19,-4,-14,27};
    minimumAbsDifference(arr);
    return 0;
}