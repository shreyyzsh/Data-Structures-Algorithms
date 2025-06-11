//Given a string s, find the length of the longest substring without duplicate characters.

#include <iostream>
#include <string>

using namespace std;

class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
        string longest_substring = "";
        int count = 0, maxCount = 0;

        for (char c : s) {
            if (longest_substring.find(c) != string::npos) {
                int pos = longest_substring.find(c);
                count = count - pos; //dvdf => vdf longest
                
                string temp = "";
                for (int i = pos+1; i < longest_substring.length(); i++) {
                    temp += longest_substring[i];
                }
                longest_substring = temp + c;
            } else {
                count += 1;
                longest_substring += c;
            }

            if (count > maxCount) maxCount = count;
        }

        return maxCount;
    }
};

int main(void) {
    Solution sol1;
    int result = sol1.lengthOfLongestSubstring("dvdf");

    cout << "\n------------result-------------" << endl;
    cout << result << endl;
    return 0;
}