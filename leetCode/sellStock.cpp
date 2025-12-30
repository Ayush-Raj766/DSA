#include<bits/stdc++.h>
using namespace std;

long long maximumProfit(vector<int>& prices, int k) {
        vector<int> diffarr;
        int n = prices.size();

        for(int i=1 ;  i<n ;i++){
            int diff = prices[i] - prices[i-1];
            diffarr.push_back(diff);
        }
        vector<int>swing ;
        for(int i = 1 ; i<n; i++){
            int swingSum = 0;
            if(diffarr[i]>0 && diffarr[i-1]>0){
                swingSum+=diffarr[i-1];
            }
            if(diffarr[i]<0 && diffarr[i-1]<0){
                swingSum+=diffarr[i-1];
            }
            swing.push_back(swingSum);
        }
        sort(swing.begin(), swing.end(), greater<int>());
        int res=0;
        for(int i = 0 ;  i<k ; i++){
            res += swing[i];
        }
        return res;
    }

int main() {
    vector <int> price ={12,16,19,19,8,1,19,13,9};
    int k = 3;
    maximumProfit(price , k);
    return 0;
}