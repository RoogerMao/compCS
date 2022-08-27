// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    // def vars and get # of #'s
    ll nums, y, x;
    ll val;
    cin >> nums;
    for(int i = 0; i < nums; i++) {
        //get coords
        cin >> y >> x;
        //if square
        if(y == x) {
            val = y * y - y + 1;
        } else if(y < x) {
            val = (x % 2 == 0) ? (x - 1) * (x - 1) + y : x * x - y + 1;
        } else {
            val = (y % 2 == 0) ? y * y - x + 1 : (y - 1) * (y - 1) + x;
        }
        cout << val << endl;
    }
    return 0;
}