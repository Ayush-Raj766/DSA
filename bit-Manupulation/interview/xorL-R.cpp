#include<bits/stdc++.h>
using namespace std;

int check(int n){
    if(n % 4 ==1) return 1;
    if(n % 4 ==2) return n+1;
    if(n % 4 ==3) return 0;

    return n;
}

void XOR(int l , int r){

    int result = check(l-1) ^ check (r);

    cout<<"result = "<<result;
}

int main() {
    int l ,r;
    cout<<"enter l = ";
    cin>>l;
    cout<<"enter R = ";
    cin>>r;
    XOR(l,r);
    return 0;
}