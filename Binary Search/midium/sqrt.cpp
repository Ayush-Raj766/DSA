#include<bits/stdc++.h>
using namespace std;

int index(int n){
    if(n ==1){
        return 1;
    }
    
    int l = 1 ;
    int r = n;
    int ans ;
    int res;
    while(r>=l){
        int mid = (l+r)/2;
        int ans = mid*mid;
        
        if(ans>n){
            r = mid -1;
        }
        else{
            l =mid+1;
            res = mid;
        }
    }
    return res;
}

int main() {
    int n;
    cout << "enter the number = ";
    cin >> n;
    

    cout << "sqrt is = " << index( n);
    return 0;
}