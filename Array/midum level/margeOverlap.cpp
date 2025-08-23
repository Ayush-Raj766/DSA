#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int a,b;
    char brack ;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<pair<int , int>>arr(n);
    for(int i = 0 ;i<n ;i++){
        cin>>arr[i].first ;
        cout<<"and";
        cin>>arr[i].second;
    }

    sort(arr.begin() , arr.end());
    //  set<vector<int>>ans;
     
       vector<pair<int, int>> merged;
    merged.push_back(arr[0]);

    for (int i = 1; i < n; i++) {
        if (arr[i].first <= merged.back().second) {
            // Overlapping -> merge
            merged.back().second = max(merged.back().second, arr[i].second);
        } else {
            // Non-overlapping -> push new interval
            merged.push_back(arr[i]);
        }
    }

     cout << "Merged intervals: ";
    for (auto it : merged) {
        cout << "[" << it.first << ", " << it.second << "] ";
    }
    cout << "\n";
    return 0;
}