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
    int k;
    // cout << "Enter the target sum k: ";
    // cin >> k;
    int maxi= 0;
    int sum = 0;
    unordered_map<int, int> mp;
    // mp[0] = 1; 
    for(int i= 0 ; i<n ; i++){
        sum +=arr[i];
        if(sum ==0){
            maxi =i+1;
        }
        else{
            if(mp.find(sum) != mp.end()){
                maxi = max(maxi , i - mp[sum]);
                // cout<<"some"<<mp[sum]<<endl;
            }
            else{
                mp[sum] =i;
                 cout<<"some"<<mp[sum]<<endl;
            }
        }
    }
    cout << "Number of subarrays with sum equal to " << " is: " << maxi << endl;
    return 0;
}