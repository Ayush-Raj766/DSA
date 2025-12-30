#include<bits/stdc++.h>
using namespace std;

int maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> minheap;
         for (int x : happiness) {
        minheap.push(x);
    }
        int count = 0 ;
    int total = 0;
        for(int i = 0 ; i < happiness.size() ; i++){
            int x = minheap.top() ;
            x = x -count;
            if(k> 0 && x >=0){
                k--;
                count++;
                total += x;
                minheap.pop();
            }
            else{
                break;
            }
        }
        return total;
    }

int main() {
    vector<int> happiness = {1,2,3};
    int k = 2;
    int x = maximumHappinessSum(happiness , k);
    cout<< x <<endl;
    return 0;
}