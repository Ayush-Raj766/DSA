#include<bits/stdc++.h>
using namespace std;

int setBit(int n , int i){
    return ((n & (1<<i)) !=0);
}

int main() {
    int n , pos;
    cout<<"enter num: ";
    cin>>n;
    cout<<"enter postion: ";
    cin>>pos;
    if(setBit(n , pos)==1){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}