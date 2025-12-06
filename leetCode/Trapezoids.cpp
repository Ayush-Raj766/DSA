#include<bits/stdc++.h>
using namespace std;

long long countTrapezoids(vector<vector<int>>& points) {
        const long long MOD = 1000000007;

        unordered_map<int, long long> freq;
        for (auto &p : points) {
            freq[p[1]]++;
        }

        vector<long long> seg;
        for (auto &it : freq) {
            long long k = it.second;
            if (k >= 2) {
                long long val = (k * (k - 1) / 2) % MOD;
                seg.push_back(val);
            }
        }

        long long sum = 0;
        long long sqSum = 0;

        for (long long x : seg) {
            sum = (sum + x) % MOD;
            sqSum = (sqSum + (x * x) % MOD) % MOD;
        }

        long long total = (sum * sum) % MOD;
        long long subtract = sqSum;

        long long ans = (total - subtract + MOD) % MOD;

        long long inv2 = (MOD + 1) / 2;  
        ans = (ans * inv2) % MOD;

        return ans;
    }
int main() {
    vector<vector<int>> points= {{-94,-36},{69,35},{39,-36},{-17,35}};
    // countTrapezoids( points);
    cout<< countTrapezoids( points)<<endl;
    return 0;
}


//problem nor 3623 #impossibble problem ..... high help of chatgpt still not able to understand it