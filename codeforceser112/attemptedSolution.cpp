#include <iostream>
#include <cmath>
using namespace std;

/* Procedure:
1. Imagine first table is in the corner of the room
2. Take two rectangles from the remaining space, so that they overlap, e.g. room: (0, 0) and (4, 4) 
    t1: (2, 2) and (4, 4) 
    r1: (0, 0) and (2, 4) 
    r2: (0, 0) and (4, 2)
3. Create ranges for the dimensions of the rectangles (2 - 4 in the example)
4. Compare dimensions of 2nd table to ranges
    a. If greater than one of the ranges, return -1
    b. If within both ranges, return -1
    c. If one is within the range, and the other is less than, return shorest dist from bottom left corner to a room corner
    d. If both are less than the range, return shortest dist of bottom left corner to dimensions of table
*/

struct rect {
    int x1, x2, y1, y2;
};

int min(int, int);
double min(double, double);

int main() {
    rect room, tableOne, spaceOne, spaceTwo, tableTwo;
    double distBL, distBR, distTL, distTR, minDist;
    
    int cases;
    cin >> cases;
    for(int i = 0; i < cases; i++) {
        room.x1 = room.y1 = 0;
        cin >> room.x2 >> room.y2;
        cin >> tableOne.x1 >> tableOne.y1 >> tableOne.x2 >> tableOne.y2;
        tableTwo.x1 = tableTwo.y1 = 0;
        cin >> tableTwo.x2 >> tableTwo.y2;
        
        spaceOne.x1 = spaceOne.y1 = spaceTwo.x1 = spaceTwo.y1 = 0;
        spaceOne.x2 = room.x2 - tableOne.x2 + tableOne.x1;
        spaceTwo.y2 = room.y2 - tableOne.y2 + tableOne.y1;
        spaceOne.y2 = room.y2; 
        spaceTwo.x2 = room.x2;
        
        if(tableTwo.x2 > room.x2 || tableTwo.y2 > room.y2) {
            cout << "-1";
        } else if(tableTwo.x2 > spaceOne.x2 && tableTwo.y2 > spaceTwo.y2) {
            cout << "-1";
        } else if(tableTwo.x2 == room.x2 || tableTwo.y2 == room.y2) {
            //dist to bl, br, tl, and tr corners in that order
            distBL = sqrt(tableOne.x1 * tableOne.x1 + tableOne.y1 * tableOne.y1);
            distBR = sqrt(
                (room.x2 - tableOne.x2) * (room.x2 - tableOne.x2) + 
                tableOne.y1 * tableOne.y1);
            distTL = sqrt(
                tableOne.x1 * tableOne.x1 +
                (room.y2 - tableOne.y2) * (room.y2 - tableOne.y2));
            distTR = sqrt(
                (room.x2 - tableOne.x2) * (room.x2 - tableOne.x2)
                + (room.y2 - tableOne.y2) * (room.y2 - tableOne.y2)
            );
            
            minDist = min(distBL, distBR);
            minDist = min(minDist, distTL);
            minDist = min(minDist, distTR);
            cout << minDist;
        } else {
            //dist to move tableOne to the bl, br, tl, and tr
            distBL = sqrt(
                (tableOne.x1 - tableTwo.x1) * (tableOne.x1 - tableTwo.x1)
                + (tableOne.y1 - tableTwo.y1) * (tableOne.y1 - tableTwo.y1));
            distBR = sqrt(
                (room.x2 - tableTwo.x2 - tableOne.x2) 
                * (room.x2 - tableTwo.x2 - tableOne.x2) 
                + (tableOne.y1 - tableTwo.y1) * (tableOne.y1 - tableTwo.y1));
            distTL = sqrt(
                (tableOne.x1 - tableTwo.x1) * (tableOne.x1 - tableTwo.x1)
                + (room.y2 - tableTwo.y2 - tableTwo.y2) 
                * (room.y2 - tableTwo.y2 - tableTwo.y2));
            distTR = sqrt(
                (room.x2 - tableTwo.x2 - tableOne.x2) 
                * (room.x2 - tableTwo.x2 - tableOne.x2) 
                + (room.y2 - tableTwo.y2 - tableTwo.y2) 
                * (room.y2 - tableTwo.y2 - tableTwo.y2));
            minDist = min(distBL, distBR);
            minDist = min(minDist, distTL);
            minDist = min(minDist, distTR);
            cout << minDist;
        }
    }
}

int min(int a, int b) {
    return ((a < b) ? a : b);
}
double min(double a, double b) {
    return ((a < b) ? a : b);
}
