#include<bits/stdc++.h>
using namespace std;

class Job{
    public:
    int id;
    int deadline;
    int profit; 
    

};

class Solution{
    public:
    static bool compare(Job a , Job b){
        int r1 =  a.profit;
        int r2 =b.profit;
        if(r1 >  r2) {
            return true;
        }
        return false;
    }
    pair <int , int> JobScheduling(Job arr[] , int n){
        sort(arr ,  arr+n , compare);

        int maxi = 0;
        for(int i = 0 ; i<n ; i++){
            maxi = max(maxi , arr[i].deadline);
        }

        vector<int> slot (maxi+1 ,  -1);

        int TotalProfit = 0 ; 
        int count = 0;

        for(int i = 0 ;  i < n ;  i++){
            for(int j = arr[i].deadline ; j >0 ; j--){
                if(slot[j] == -1){
                    slot[j] = arr[i].id;

                    count++ ;

                    TotalProfit += arr[i].profit;
                    break;
                }
            }
        }

        return make_pair(count , TotalProfit);
    }
};

int main() {
    const int n = 4;
   // Define jobs with id, deadline, and profit
   Job arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};

   Solution ob;
   // Function call to find the number of jobs done and total profit
   pair < int, int > ans = ob.JobScheduling(arr, n);

   // Output the number of jobs and the total profit
   cout << ans.first << " " << ans.second << endl;
    return 0;
}