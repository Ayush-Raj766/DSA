#include<bits/stdc++.h>
using namespace std;

int index(int n, int m){
    if(n ==1){
        return 1;
    }
    
    int l = 1 ;
    int r = n;
    int ans ;
    int res;
    while(r>=l){
        int mid = (l+r)/2;
        // for(int i =0; i<m;i++){
        //      ans = ans *mid;
        // }
        ans = pow(mid , m);
        // cout<<"ans = "<<ans<<endl;
        
        if(ans>n){
            r = mid -1;
        }
        else{
            l =mid+1;
            res = mid;
        }
        ans =1;
    }
    return res;
}

int main() {
    int n ,m;
    cout << "enter the number = ";
    cin >> n;
    cout<<"num of root =";
    cin>> m;
    index(n ,m);
    cout <<m<< "rt is = " << index( n, m);
    return 0;
}