#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
    //get factorial
    ll factorial;
    cin >> factorial;
    ll pow5 = 1;
    ll tens = 0;
    
    //take the # of multiples of 5 
    while((ll) (pow(5, pow5)) <= factorial) {
        tens += factorial / ((ll) (pow(5, pow5)));
        pow5++;
    }
    
    cout << tens;
    return 0;
}
