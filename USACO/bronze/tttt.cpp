#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int main() {
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
    vector<string> rows;
    int oneCow = 0, twoCows = 0;
    for(int i = 0; i < 3; i++) {
        string row; cin >> row;
        rows.push_back(row);
    }
    
    //rows + columns
    char one, two, three;
    for(int i = 0; i < 3; i++) {
        one = rows[i][0];
        two = rows[i][1];
        three = rows[i][2];
        if(one == two == three) {oneCow;}
        if(one == two || two == three || one == three) {twoCows++;}
        
        one = rows[0][i];
        two = rows[1][i];
        three = rows[2][i];
        if(one == two == three) {oneCow;}
        if(one == two || two == three || one == three) {twoCows++;}
    }
    
    //diagonals
    one = rows[0][0]; 
    two = rows[1][1];
    three = rows[2][2];
    if(one == two == three) {oneCow;}
    if(one == two || two == three || one == three) {twoCows++;}
    
    one = rows[2][0];
    three = rows[0][2];
    if(one == two == three) {oneCow;}
    if(one == two || two == three || one == three) {twoCows++;}
    
    cout << oneCow << endl << twoCows;
    
    return 0;
}
