#include <iostream>
#include <array>
#include <cstring>
#include <climits>
#include <cstdio>

using namespace std;

array<array<int, 2001>, 2001> timeVisited;
int x = INT_MAX, t = 1;
int fjx = 1000, fjy = 1000;

void move(char direction, int dist) {
    int dx = 0, dy = 0;
    switch (direction) {
        case 'N': dy = 1; break;
        case 'S': dy = -1; break;
        case 'W': dx = -1; break;
        case 'E': dx = 1; 
    }
    for(int i = 0; i < dist; i++) {
        fjx += dx;
        fjy += dy;
        if(timeVisited[fjx][fjy] != -1) {
            x = min(t - timeVisited[fjx][fjy], x);
        }
        timeVisited[fjx][fjy] = t;
        t++;
    }
    
}

int main() {
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    int n; cin >> n;
    memset(&timeVisited[0][0], -1, sizeof(timeVisited));
    timeVisited[1000][1000] = 0;
    while(n--) {
        char direction; int dist;
        cin >> direction >> dist;
        move(direction, dist);
    }
    cout << ((x == INT_MAX) ? -1 : x);

    return 0;
}
