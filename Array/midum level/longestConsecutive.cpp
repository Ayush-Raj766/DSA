#include<bits/stdc++.h>
using namespace std;

int main() {
    int n ;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int longest = 1;
    unordered_set<int>set;
    for(int i =0 ; i<n ;i++){
        set.insert(arr[i]);

    }
    for(auto it :set){
         if(set.find(it-1) == set.end()){
            int cunt=1;
            int x=it;
            while(set.find(x+1)!=set.end()){
                x=x+1;
                cunt=cunt+1;

            }
            longest = max(longest , cunt);

         }
    }

    cout<<"longest consecutive array is:"<<longest;
    return 0;
}