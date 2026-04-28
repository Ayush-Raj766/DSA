#include<bits/stdc++.h>
using namespace std;

class Robot {
public:
    int w, h;
    int x, y;
    int dir;
    int cycle;

  vector<string> dirStr = {"East", "North", "West", "South"};
vector<pair<int,int>> directions = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0;
        y = 0;
        dir = 0;

        cycle = 2 * (w + h) - 4;
        
    }
    
    void step(int num) {
    if (cycle == 0) return;

    num = num % cycle;

    if (num == 0) {
        if (x == 0 && y == 0) {
            dir = 3; // South
        }
        return;
    }

    while(num > 0){
        int newx = x + directions[dir].first;
        int newy = y + directions[dir].second;

        if(newx < 0 || newx >= w || newy < 0 || newy >= h){
            dir = (dir + 1) % 4;
        } else {
            x = newx;
            y = newy;
            num--;
        }
    }
}
       
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return dirStr[dir];
    }
};



int main() {

    Robot obj(4, 3);

obj.step(2);
auto pos = obj.getPos();   // {2,0}
auto dir = obj.getDir();   // "East"

cout << "Position after 2 steps: (" << pos[0] << ", " << pos[1] << ")" << endl;
cout << "Direction after 2 steps: " << dir << endl;

obj.step(5);
pos = obj.getPos();        // {1,2}
dir = obj.getDir();        // "West"

cout << "Final Position: (" << pos[0] << ", " << pos[1] << ")" << endl;
cout << "Final Direction: " << dir << endl;
    
    return 0;
}