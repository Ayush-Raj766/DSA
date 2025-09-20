#include<bits/stdc++.h>
using namespace std;

int flip(int a , int b){
    int res = a^b;

    int count =0;
    for(int i =0 ; i<32 ; i++){
        if((res &(1<<i))!=0){
            count++;
        }
    }
    return count;
}

int main() {
    int a,b;
    cout<<"start = ";
    cin>>a;
    cout<<"goal = ";
    cin>>b;
    cout<<"flip = "<<flip(a,b);
    return 0;
}