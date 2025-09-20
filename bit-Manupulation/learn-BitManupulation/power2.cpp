#include<bits/stdc++.h>
using namespace std;

bool powerBit(int n ){
    if ((n & (n-1)) ==0){
        return true;
    };
    return false;
}

int main() {
    int n , pos;
    cout<<"enter num: ";
    cin>>n;
    if(powerBit(n)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}