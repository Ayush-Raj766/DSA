#include<bits/stdc++.h>
using namespace std;

int fect(int n){

    if(n == 1 ||n ==0){
        return 1;
    }

    return n* fect(n-1);

}

int main() {
    int n;
    cout<<"enter nor of row =";
    cin>>n;
    int r;
    cout<<"enter nor of col: ";
    cin>>r;
    int res;
    res = fect(n)/(fect(r)*fect(n-r));
    cout<<"result is "<<res<<endl;
    for(int i =0 ; i<n;i++){
        for(int j = 0 ; j<=i ; j++){
            res = fect(i)/(fect(j)*fect(i-j));
            cout<<res;
        }
        cout<<endl;
    }

    
    return 0;
}