#include <bits/stdc++.h>
using namespace std;

vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
{
    int n = positions.size();
    vector<pair<int, int>> robots(n);
    for (int i = 0; i < n; i++)
    {
        robots[i] = {positions[i], i};
    }
    sort(robots.begin(), robots.end());
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        int idx = robots[i].second;
        if (directions[idx] == 'R')
        {
            st.push(idx);
        }
        else
        {
            while (!st.empty() && healths[st.top()] < healths[idx])
            {
                healths[idx] -= 1;
                st.pop();
            }
            if (st.empty())
            {
                continue;
            }
            if (healths[st.top()] == healths[idx])
            {
                st.pop();
            }
            else
            {
                healths[st.top()] -= 1;
            }
        }
    }
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        if (healths[i] > 0)
        {
            result.push_back(healths[i]);
        }
    }
    return result;
}

int main()
{
    vector<int> positions = {3, 5, 2, 6};
    vector<int> healths = {10, 11, 12, 13};
    string directions = "RLRL";
    vector<int> result = survivedRobotsHealths(positions, healths, directions);
    return 0;
}