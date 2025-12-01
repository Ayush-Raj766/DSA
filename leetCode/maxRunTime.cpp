#include<bits/stdc++.h>
using namespace std;

bool canRun(vector<int> &battreris ,  long long t , int n){
    long long total = 0 ;
    for(int i = 0 ; i < battreris.size() ; i++){
        total += min((long long)battreris[i] , t);
    }
    return total >= t * n ;

}

long long maxRuntime(vector<int> &batteries , int n ){
    long long l = 0;
    long long r =accumulate(batteries.begin() ,  batteries.end() , 0)/n;
    long long ans = 0 ;
    while (r>=l){
        int mid =  (l+r)/2;

        if(canRun(batteries,mid, n)){
            ans = mid ;
            l = mid + 1 ;
        }
        else{
            r = mid - 1 ;
        }
    }
    return ans;
}

int main() {
    vector <int> batteries = {10, 10, 5,3};
    int numberComputer = 3;

    maxRuntime(batteries, numberComputer);
    cout << "Maximum runtime for " << numberComputer << " computers is: " << maxRuntime(batteries, numberComputer) << " units." << endl;
    return 0;
}