#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countDigit(int num){
        int x = num;
        int count = 0;
        while(x>0){
            x=x/10;
            count++;
        }
        return count;
    }
    vector<int> sequentialDigits(int low, int high) {
        int lSize = countDigit(low);
        int hSize = countDigit(high);

        vector<int>ans;

        for(int i = lSize; i <= hSize; i++){
            int start = 1;
            int end = 10 - i;
            for(int j = start; j <= end; j++){
                int num = 0;
                for(int k = 0; k < i; k++){
                    num = num * 10 + (j + k);
                }
                if(num >= low && num <= high){
                    ans.push_back(num);
                }
            }
        }

        return ans;
    }
};

int main() {
    int low = 100;
    int high = 3000;
    Solution sol;
    vector<int> result = sol.sequentialDigits(low, high);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}