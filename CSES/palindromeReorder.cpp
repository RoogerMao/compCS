#include <iostream>
using namespace std;

int main() {
    //input string 
    string input;
    cin >> input;
    
    //count characters
    int chars[26];
    for(int i = 0; i < 26; i++) {
        chars[i] = 0;
    }
    for(int i = 0; i < input.length(); i++) {
        chars[(int) (input[i]) - (int) ('A')]++;
    }
    
    //check if counts of other characters are even
    int odds = 0; 
    int j = 0; 
    while(j < 26 && odds < 2) {
        if(chars[j] % 2 == 1) {
            odds++;
        }
        j++;
    }
    
    //display results
    if(odds < 2) {
        //find letter with odd occurances (if input string has odd #) and place in center
        if(input.length() % 2 == 1) {
            bool found = false;
            int i = 0;
            while(!found) {
                if(chars[i] % 2 == 1) {
                    input[input.length() / 2] = (char) (65 + i);
                    chars[i]--;
                    found = true;
                }
                i++;
            }
        }
        //go through rest of characters
        int pos = 0;
        for(int i = 0; i < 26; i++) {
            for(int k = 0; k < chars[i] / 2; k++) {
                input[pos] = (char) (65 + i);
                input[input.length() - 1 - pos] = (char) (65 + i);
                pos++;
            }
        }
        
        cout << endl << input;
    } else {
        cout << "NO SOLUTION";
    }
}
