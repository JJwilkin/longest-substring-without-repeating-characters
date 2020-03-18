#include <iostream>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string s);

int main () {
    string input [] = {"au", "", "bbbbb", "abcabcad", "dvdf","abcabcbb"};
    int expected_output [] = {2,0,1,3,3,3};
    for (int i = 0; i < sizeof(expected_output)/sizeof(expected_output[0]); i++ ) {
        cout << "Expected Output: " << expected_output[i] << endl;
        cout << "Actual Output: " << lengthOfLongestSubstring(input[i]) << endl;
        cout << "=======================================" << endl;
    }
    
}

int lengthOfLongestSubstring(string s) {
     if(!s.length()) return 0;
      int max_length = 1;
      vector <char> substring;
    int count = 1;
      bool repeated = false;
      int pos = 0;
    while (pos < s.length()) {
        int i = 0;
        while (i < substring.size() && !repeated) {
            if(s[pos] == substring[i]) {
                if(substring.size() > max_length) {
                    max_length = substring.size();
                }
                substring.clear();
                repeated = true;
            }
        }
       substring.push_back(s[pos]);
        pos++;
        
    }
         if(substring.size() > max_length) {
                    max_length = substring.size();
                }
// cout << endl << "this is count: " << count << endl;
        return max_length;
    }