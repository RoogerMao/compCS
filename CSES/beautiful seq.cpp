// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    //input 
    int n; cin >> n;
    
    //cases of 1 - 4 + algorithm for anything larger
    switch (n) {
        case 1: 
            cout << "1"; break;
        case 2:
        case 3: 
            cout << "NO SOLUTION"; break;
        case 4:
            cout << "2 4 1 3"; break;
        default:
            //print out odds
            for(int i = 1; i <= n; i += 2) {
                cout << i << " ";
            }
            //print out evens
            for(int i = 2; i <= n; i += 2) {
                cout << i << " ";
            }
    }
    
    return 0;
}