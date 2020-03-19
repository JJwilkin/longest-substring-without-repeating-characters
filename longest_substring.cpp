#include <iostream>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string s);

int main () {
    string input [] = {"au", "", "bbbbb", "abcabcad", "dvdf","abcabcbb"};
    int expected_output [] = {2,0,1,4,3,3};
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
    for (int pos = 0; pos < s.length(); pos++) {
        repeated = false;
        int check = pos +1;
        if (!substring.size()) substring.push_back(s[pos]); //If  substring is empty add current element to substring
        
        while(check < s.length() && !repeated) { //iterate through the rest of the list until a repeat is found or reaches the end

            int substring_index = 0;
            while (substring_index < substring.size() && !repeated) { //iterate through substring to check if s[check] already appears if not, add check to substring and increment 
                if(s[check] == substring[substring_index]) {
                    //if s[check] is already in substring check if it is substring length is longer than max_length, if not set it
                    if(substring.size() > max_length) max_length = substring.size();
                    substring.clear();
                    repeated = true;
                }
                substring_index++;
            }
            //If s[check] is not found in substring, add it to substirng and increment check
            if(!repeated) substring.push_back(s[check]);
            check++;
        }
        
    }
         if(substring.size() > max_length) {
                    max_length = substring.size();
                }
        return max_length;
    }