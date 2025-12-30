#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:

    int candy(vector<int>& rating){
       int n = rating.size();
        int sum = n ;
        int i = 1;
        

        while(i< n ){
            if(rating[i] == rating[i-1]){
                // sum ++;
                i++;
                continue;
            }
            int peak = 0 ;
            while(i<n && rating[i] > rating[i-1]){
                peak++;
                sum += peak;
                i++;
            }
            int down = 0;
            while(i<n && rating[i] < rating[i-1]){
                down++;
                sum += down;
                i++;
            }
            sum -= min(peak, down);
        }
        return sum;
    }
};
int main() {
    Solution sol;

    // Input array of ratings
    vector<int> ratings = {1, 3, 6, 8, 9, 5, 3};

    // Call function and print result
    cout << "Minimum candies required: " << sol.candy(ratings) << endl;

    return 0;
}