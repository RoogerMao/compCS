// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    // input
    ll n;
    scanf("%lld", &n);

    while(n != 1) {
        printf("%lld ", n);
        if(n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
    }
    printf("%lld", 1);
}