#include<bits/stdc++.h>
using namespace std;

void swap(int a,int b){
    a= a^b;
    b=a^b;
    a=a^b;

    cout <<"number 1="<<a<<endl;
    cout <<"number 2="<<b<<endl;
}

int main() {
    int a, b;
    cout<<"number 1 =";
    cin>>a;
    cout<<"number 2 =";
    cin>>b;
    swap(a,b);
    return 0;
}