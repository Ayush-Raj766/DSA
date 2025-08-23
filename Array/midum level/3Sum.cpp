// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cout << "enter size of array = ";
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     set<vector<int>> st;
    

//     for (int i = 0; i < n ; i++)
//     {
//         set<int> mpp;
//         for (int j = i + 1; j < n - 1; j++)
//         {
//             int third = -(arr[i] + arr[j]);

//             if (mpp.find(third) != mpp.end())
//             {
//                 vector<int> temp = {arr[i], arr[j], third};
//                 sort(temp.begin(), temp.end());
//                 st.insert(temp);
//             }
//             mpp.insert(arr[j]);
//         }
//     }
//     vector<vector<int>> ans(st.begin() , st.end());

//     for (auto it : ans) {
//         cout << "[";
//         for (auto i : it) {
//             cout << i << " ";
//         }
//         cout << "] ";
//     }
//     cout << "\n";
//     return 0;
// }







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

    sort(arr.begin() , arr.end());
    set<vector<int>>ans;
    for(int i = 0 ; i<n ;i++){
        int  j=i+1 , k =n-1;
        while(j<k){
            int sum = arr[i] +arr[j] + arr[k];
            if(sum<0){
                j++;
            }
            else if(sum>0){
                k--;
            }
            else{
                vector<int>temp={arr[i] , arr[j],arr[k]};
                ans.insert(temp);
                j++;
                k--;
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