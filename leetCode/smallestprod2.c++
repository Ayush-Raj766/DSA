#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<long long> primeFactors(long long n) {
        vector<long long> factors;

        while (n > 1) {

            if (n % 2 == 0) {
                factors.push_back(2);
                n /= 2;
            }
            else if (n % 3 == 0) {
                factors.push_back(3);
                n /= 3;
            }
            else if (n % 5 == 0) {
                factors.push_back(5);
                n /= 5;
            }
            else if (n % 7 == 0) {
                factors.push_back(7);
                n /= 7;
            }
            else {
                factors.push_back(n);
                break;
            }
        }

        return factors;
    }

   
    vector<int> getFactors(int digit) {

        vector<int> f(4, 0);

        while (digit % 2 == 0) {
            f[0]++;
            digit /= 2;
        }

        while (digit % 3 == 0) {
            f[1]++;
            digit /= 3;
        }

        while (digit % 5 == 0) {
            f[2]++;
            digit /= 5;
        }

        while (digit % 7 == 0) {
            f[3]++;
            digit /= 7;
        }

        return f;
    }

    string smallestNumber(string num, long long t) {

       

        vector<long long> factors = primeFactors(t);

        // If t contains a factor other than 2,3,5,7,
        // it is impossible.
        for (long long factor : factors) {

            if (factor != 2 &&
                factor != 3 &&
                factor != 5 &&
                factor != 7) {

                return "-1";
            }
        }

       

        int need2 = 0;
        int need3 = 0;
        int need5 = 0;
        int need7 = 0;

        for (long long factor : factors) {

            if (factor == 2)
                need2++;

            else if (factor == 3)
                need3++;

            else if (factor == 5)
                need5++;

            else if (factor == 7)
                need7++;
        }

     

        auto solveLength = [&](int len, bool sameLength) -> string {

            unordered_map<string, bool> memo;

           

            function<bool(int, int, int, int, int, bool)> possible;

            possible = [&](int pos,
                           int a,
                           int b,
                           int c,
                           int d,
                           bool tight) -> bool {

                
                if (pos == len) {
                    return a == 0 &&
                           b == 0 &&
                           c == 0 &&
                           d == 0;
                }

                string key =
                    to_string(pos) + "," +
                    to_string(a) + "," +
                    to_string(b) + "," +
                    to_string(c) + "," +
                    to_string(d) + "," +
                    to_string(tight);

                if (memo.count(key))
                    return memo[key];

                int start = 1;

                if (sameLength && tight) {
                    start = num[pos] - '0';

                    // 0 is not allowed
                    start = max(start, 1);
                }

                for (int digit = start; digit <= 9; digit++) {

                    vector<int> f = getFactors(digit);

                    int na = max(0, a - f[0]);
                    int nb = max(0, b - f[1]);
                    int nc = max(0, c - f[2]);
                    int nd = max(0, d - f[3]);

                    bool ntight = false;

                    if (sameLength && tight) {
                        ntight = (digit == num[pos] - '0');
                    }

                    if (possible(pos + 1,
                                 na, nb, nc, nd,
                                 ntight)) {

                        return memo[key] = true;
                    }
                }

                return memo[key] = false;
            };

            // Check whether a solution exists
            if (!possible(0,
                          need2,
                          need3,
                          need5,
                          need7,
                          sameLength)) {

                return "";
            }

            

            string ans = "";

            int a = need2;
            int b = need3;
            int c = need5;
            int d = need7;

            bool tight = sameLength;

            for (int pos = 0; pos < len; pos++) {

                int start = 1;

                if (sameLength && tight) {
                    start = max(1, num[pos] - '0');
                }

                for (int digit = start; digit <= 9; digit++) {

                    vector<int> f = getFactors(digit);

                    int na = max(0, a - f[0]);
                    int nb = max(0, b - f[1]);
                    int nc = max(0, c - f[2]);
                    int nd = max(0, d - f[3]);

                    bool ntight = false;

                    if (sameLength && tight) {
                        ntight =
                            (digit == num[pos] - '0');
                    }

                    if (possible(pos + 1,
                                 na, nb, nc, nd,
                                 ntight)) {

                        ans += char('0' + digit);

                        a = na;
                        b = nb;
                        c = nc;
                        d = nd;

                        tight = ntight;

                        break;
                    }
                }
            }

            return ans;
        };

      

        string ans = solveLength(num.size(), true);

        if (ans != "")
            return ans;

        
        for (int len = num.size() + 1;
             len <= num.size() + 70;
             len++) {

            ans = solveLength(len, false);

            if (ans != "")
                return ans;
        }

        return "-1";
    }
};


int main() {

    Solution sol;

    string num = "1234";
    long long t = 256;

    cout << sol.smallestNumber(num, t) << endl;

    return 0;
}