#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
    //get length of bit string
    ll len;
    cin >> len;
    ll currentMod = 1;
    ll mod = (ll) (pow(10, 9) + 7);
    
    //build up to len to prevent overflow
    while(len >= 31) {
        currentMod = (currentMod * ((ll) (pow(2, 31)) % mod)) % mod;
        len -= 31;
    }
    
    //once len < 31
    currentMod = (currentMod * ((ll) (pow(2, len)) % mod)) % mod;
    cout << currentMod;
}
