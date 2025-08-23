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
    cout << "Enter the target k: ";
    cin >> k;
    int count = 0;
    int prifixXOR = 0;
    unordered_map<int, int> mp;

    mp[prifixXOR]++; 
    for(int i= 0 ; i<n ; i++){
        prifixXOR =prifixXOR ^ arr[i];
        int remove = prifixXOR ^ k;
        
        // cout << "Current prefix sum: " << prifixXOR << ", looking for: " << remove << endl;
            count += mp[remove];
            // cout << "Count after adding occurrences of " << remove << ": " << count << endl;
        mp[prifixXOR]++;
    }
    cout << "Number of subarrays with sum equal to " << k << " is: " << count << endl;
    return 0;
}