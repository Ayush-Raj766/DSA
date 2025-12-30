#include<bits/stdc++.h>
using namespace std;

vector<int> minCoins(int v){
 int coin[] = {1 , 2 , 5 , 10 , 20 ,50 , 100 , 200 , 500 , 2000};
  int n = sizeof(coin) / sizeof(coin[0]);

 vector<int> ans;

 for(int i = n-1 ;  i >= 0 ; i--){

    while (v >= coin[i]){
        v -= coin[i];
        ans.push_back(coin[i]);
    }
 }
 return ans;
}


int main() {
     int V = 49;

    // Call function to get coin list
    vector<int> ans = minCoins(V);

    // Print result
    cout << "The minimum number of coins is " << ans.size() << endl;
    cout << "The coins are " << endl;
    for (int coin : ans) {
        cout << coin << " ";
    }
    cout << endl;
 
    return 0;
}