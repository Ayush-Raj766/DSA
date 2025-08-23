#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int target;
    cout<<"target = ";
    cin>>target;

    sort(arr.begin() , arr.end());
    set<vector<int>>ans;
    for(int i =0;i<n;i++){
        for(int j=i+1 ;j<n; j++){
            int k= j+1;
            int l = n-1;
            while(k<l){
                long long sum = arr[i] + arr[j] +arr[k] +arr[l];
                if(sum<target){
                    k++;
                }
                else if(sum>target){
                    l--;
                }
                else{
                vector<int>temp={arr[i] , arr[j],arr[k] , arr[l]};
                ans.insert(temp);
                k++;
                l--;
            }
            }
        }
    }

    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}