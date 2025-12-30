#include <bits/stdc++.h>
using namespace std;

int mostBooked(vector<vector<int>> &meetings  ,int n)
{

    sort(meetings.begin(), meetings.end());
    priority_queue<int , vector<int> , greater<int>> freeRoom;

    for(int i = 0 ; i<n; i++){
        freeRoom.push(i);
    }

    priority_queue<pair<long long , int> ,  vector<pair<long long , int>> , greater<pair<long long , int>>> busyRoom;

    vector<int> count(n,0);

    for(auto &it : meetings){
        long long startTime = it[0];
        long long endTime = it[1];
        long long duration = endTime - startTime;

        while(!busyRoom.empty() && busyRoom.top().first <= startTime){
            freeRoom.push(busyRoom.top().second);
            busyRoom.pop();
        }


        if (!freeRoom.empty()) {
                int room = freeRoom.top();
                freeRoom.pop();
                busyRoom.push({endTime, room});
                count[room]++;
            } 

            else {
                auto [endTime, room] = busyRoom.top();
                busyRoom.pop();

                long long newEnd = endTime + duration;
                busyRoom.push({newEnd, room});
                count[room]++;
            }
    }
    int ans = 0;
        for (int i = 1; i < n; i++) {
            if (count[i] > count[ans]) {
                ans = i;
            }
        }

        return ans;

}

int main()
{
    vector<vector<int>> meetings = {{1, 20}, {2, 10}, {3, 5}, {4, 9}, {6, 8}};
    int n = 3;
    mostBooked(meetings, n);
    return 0;
}