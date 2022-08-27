// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    // input number + array to manage sets
    ll num;
    cin >> num;
    bool big[num];
    
    //set default values in bool to false
    for(int i = 0; i < num; i++) {
        big[i] = false;
    }
    
    //logic for if the sum of 1, 2, ... n can be put into 2 sets
    if(num % 4 == 0 || num % 4 == 3) {
        cout << "YES" << endl;
        //determine sets
        ll setSum = ((num) * (num + 1)) / 4;
        ll currentSum = 0;
        int counter = 0;
        for(int i = num; i > 0; i--) {
            //greedy algorithm
            if(currentSum + i <= setSum) {
                currentSum += i;
                big[i - 1] = true;
                counter++;
            }
        }
        //display sets
        cout << counter << endl;
        for(int j = 0; j < num; j++) {
            if(big[j]) {
                cout << j + 1 << " ";
            } 
        }
        cout << endl << num - counter << endl;
        for(int j = 0; j < num; j++) {
            if(!big[j]) {
                cout << j + 1 << " ";
            }
        }
    } else {
        cout << "NO";
    }
    
}