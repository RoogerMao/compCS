#include <iostream>
using namespace std;
typedef long long ll;
int main() {
    //get number of scenarios
    int scen;
    cin >> scen;
    int one, two;
    
    //loop through
    for(int i = 0; i < scen; i++) {
        cin >> one >> two;
        if(two > one) {
            int temp = one;
            one = two;
            two = temp;
        }
        
        //compare ratios
        if(two > 0) {
            if(2 * two >= one) {
                if((one + two) % 3 == 0) {
                    cout << "YES";
                } else {
                    cout << "NO";
                }
            } else {
                cout << "NO";
            }
        } else {
            if(one == 0 && two == 0) {
                cout << "YES";
            } else {
                cout << "NO";
            }
        }
        cout << endl;
    }
}
