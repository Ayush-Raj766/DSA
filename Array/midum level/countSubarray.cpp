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
    cout << "Enter the target sum k: ";
    cin >> k;
    int count = 0;
    int prifixSum = 0;
    unordered_map<int, int> mp;
    mp[0] = 1; 
    for(int i= 0 ; i<n ; i++){
        prifixSum +=arr[i];
        int remove = prifixSum - k;
        cout << "Current prefix sum: " << prifixSum << ", looking for: " << remove << endl;
            count += mp[remove];
            cout << "Count after adding occurrences of " << remove << ": " << count << endl;
        mp[prifixSum]++;
    }
    cout << "Number of subarrays with sum equal to " << k << " is: " << count << endl;
    return 0;
}