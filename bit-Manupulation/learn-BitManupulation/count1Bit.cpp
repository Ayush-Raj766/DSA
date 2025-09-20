#include<bits/stdc++.h>
using namespace std;

int count(int n){
    int count =0;
    for(int i =0 ; i<32 ; i++){
        if((n &(1<<i))!=0){
            count++;
        }
    }
    return count;
}

int main() {
    int n ;
    cout<<"enter num: ";
    cin>>n;
    cout<<"count = "<<count(n);
    return 0;
}