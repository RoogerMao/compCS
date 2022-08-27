// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    // array size = n
    int n, m;
    cin >> n;
    bool arr[n];
    
    //default of false
    for(int i = 0; i < n; i++) {
        arr[i] = false;
    }
    
    //check off numbers and making array 1-based
    for(int i = 0; i < n - 1; i++) {
        cin >> m;
        arr[m - 1] = true;
    }
    
    //loop through to find unchecked
    int j = 0;
    while(arr[j] == true) {
        j++;
    }
    cout << ++j;
}