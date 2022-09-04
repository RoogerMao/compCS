//solution method is from saksham rustagi under bronze > getting started > rectangle geometry > b. two tables
#include <iostream>
#include <climits>
using namespace std;
typedef long long ll;

int main() {
    int cases; cin >> cases;
    ll roomX, roomY, tableOneBottomLeftX, tableOneBottomLeftY, tableOneTopRightX, tableOneTopRightY, tableTwoWidth, tableTwoHeight;
    ll distance;
    
    while(cases--) {
        //for the second if statement min()
            // we need distance to be defined in order to compare it to the other expression
        distance = LLONG_MAX; 
        bool fits = false;
        cin >> roomX >> roomY;
        //the second table is always guaranteed to fit in the room by itself
        cin >> tableOneBottomLeftX >> tableOneBottomLeftY >> tableOneTopRightX >> tableOneTopRightY >> tableTwoWidth >> tableTwoHeight;
        int tableOneWidth = tableOneTopRightX - tableOneBottomLeftX;
        int tableOneHeight = tableOneTopRightY - tableOneTopRightY;
        
        if(tableOneWidth + tableTwoWidth <= roomX) {
            //roomX - tableOneTopRightX is the distance from the table to the right wall
            //tableOneBottomLeftX is the distance from the table to the left wall
            
            //you take max() of the two because whichever edge is farther from their respective wall requires you to move the first table less e.g.
            //if tableTwo is 4 wide and tableOne is 3 away from the left wall and 2 away from the right wall, you move it away from the left wall because you only have to move it (4 - 3) instead of (4 - 2)
            
            //taking the final max allows you to determine if you need to move the table horizontally
            fits = true;
            distance = max(tableTwoWidth - max(roomX - tableOneTopRightX, tableOneBottomLeftX), (ll) 0);
        }
        if(tableOneHeight + tableTwoHeight <= roomY) {
            //roomY - tableOneTopRight is distance from table to top wall
            //tableOneBottomLeftY is distance from table to bottom wall
            
            //take the max() of the distance from the top of the first table to the top wall and the distance from the bottom of the first table to the bottom wall for same reasons
            
            //outermost max() allows you to see if you need to move the 2nd table vertically
            
            //you only need to move the first table vertically or horizontally, not a combination
            //to make sure you're moving it the least distance, take the min() of the horizontal distance (if applicable) and the vertical
            
            fits = true;
            distance = min(distance, max(tableTwoHeight - max(roomY - tableOneTopRightY, tableOneBottomLeftY), (ll) 0));
        }
        if(!fits) {
            cout << -1 << "\n";
        } else {
            cout << distance << "\n";
        }
    }
}
