#include <bits/stdc++.h>
using namespace std;

void recperm(vector<int>& ds, vector<int>& arr, vector<vector<int>>& ans, vector<int>& trav, int n) {
    if(ds.size() == n) {
        ans.push_back(ds);
        return;
    }
    for(int i = 0; i < n; i++) {
        if(trav[i] == 0) {
            ds.push_back(arr[i]);
            trav[i] = 1;
            recperm(ds, arr, ans, trav, n);
            ds.pop_back();
            trav[i] = 0;
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> trav(n, 0);
    vector<vector<int>> ans;
    vector<int> ds;

    recperm(ds, arr, ans, trav, n);

    cout << "Permutations of the array:" << endl;
    for(auto &it : ans) {
        for(auto &i : it) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
