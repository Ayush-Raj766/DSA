#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> apple = {1, 3 , 5};
    vector<int> capacity = {4,3,1,5,2};
    int totalApple = 0 ;
    int n = apple.size();
    for(int i = 0 ; i<n ; i++){
        totalApple += apple[i];
    }
    sort(capacity.begin() , capacity.end() ,  greater());
    int capacitytotal = 0 ;
    int count = 0 ;
    for(int i = 0 ;i < capacity.size() ;  i++){
        if(capacitytotal<totalApple){
            count++;
            capacitytotal += capacity[i];
        }
        else{
            break;
        }
    }

    cout<< count <<endl;
    return 0;
}