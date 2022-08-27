// Online C++ compiler to run C++ program online
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
    // def vars and get # of #'s
    ll boards, knights; 
    cin >> boards;
    
    //loop and print
    for(ll i = 1; i <= boards; i++) {
        if(i == 1) {
            cout << 0 << endl;
        } else if (i == 2) {
            cout << 6 << endl;
        } else {
            knights =  (pow(i, 4) - i * i) / 2 - 4 * (i - 1) * (i - 2);
            cout << knights << endl;
        }
    }
    return 0;
}