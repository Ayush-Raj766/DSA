#include<bits/stdc++.h>
using namespace std;

class Item {
public:
    int val;
    int weight;
};

class Solution{
    public:

   static bool comperator(Item a ,Item b){
        double r1 = (double)a.val/a.weight;
        double r2 = (double)b.val/b.weight;

        if(r1>r2) {return true;}
        return false;
    }

     double fractionalKnapsack(int W, Item arr[], int n){
        sort(arr , arr+n ,comperator);

        double total =0.0;

        for(int i = 0 ; i < n ; i++){
            if(W>=arr[i].weight){
                W -= arr[i].weight;
                total += arr[i].val;
            }
            else{
                double res = (double)(arr[i].val/arr[i].weight)*W;
                total += res;
                break;
            }
        }
        return total;
     }
};

int main() {
     const int n = 3, weight = 50;

    Item arr[n] = { {100,20}, {60,10}, {120,30} };

    Solution obj;
    double ans = obj.fractionalKnapsack(weight, arr, n);

    cout << "The maximum value is " << fixed << setprecision(2) << ans;
    return 0;
}