#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum = 0, rightSum = 0;
        int n = cardPoints.size();
        for(int i = 0; i < k; i++) {
            leftSum += cardPoints[i];
        }
        int maxSum = leftSum;
        for(int i = 0; i < k; i++) {
            leftSum -= cardPoints[k - 1 - i];
            rightSum += cardPoints[n - 1 - i];
            maxSum = max(maxSum, leftSum + rightSum);
        }
        return maxSum;
    }
};

int main() {
    vector<int> cards = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;

    // Create object of Solution class
    Solution sol;

    cout << sol.maxScore(cards, k) << endl;
    return 0;
}