// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    //create array to store input
    int n; cin >> n;
    int arr[n];
    //input into array
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    //loop through the array so that it meets the condition 
    int prev = arr[0]; ll counter = 0;
    for(int i = 1; i < n; i++) {
        if(prev > arr[i]) {
            //count addition
            counter += prev - arr[i];
            arr[i] += prev - arr[i];
        }
        prev = arr[i];
    }
    
    //output counter
    cout << counter;
    return 0;
}