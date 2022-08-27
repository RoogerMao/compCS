// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    //input string
    string seq;
    cin >> seq;
    //curr letter
    char prev = seq[0];
    //vars to see longest seq
    int streak = 1;
    int max = 1;
    
    //loop through entire string
    for(int i = 1; i < seq.length(); i++) {
        //see if streak continues
        if(prev == seq[i]) {
            streak++;
            //compare max to streak
            max = (streak > max) ? streak : max;
        } else {
            streak = 1;
        }
        //update cur
        prev = seq[i];
    }
    
    //return max
    cout << max;
}