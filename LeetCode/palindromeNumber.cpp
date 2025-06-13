// palindrome number

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {

        string x_str = to_string(x);
        vector<char> checkPalindrome;

        for (char c : x_str) {
            checkPalindrome.push_back(c);
        }

        auto rit = checkPalindrome.rbegin();

        for (int i = 0; i < checkPalindrome.size(); i++) {
            if (checkPalindrome[i] != *rit) return false;
            ++rit;
        }

        return true;
        
    }
};


int main(void) {
    Solution newSol;
    int x = 121;
    bool result = newSol.isPalindrome(121);

    if (result) {
        cout << "\nlfg\n";
    } else cout << "\ntf\n";

    return 0;
}

// 121
// i = 0 => x_str[i] : 1 
// j = 2 => x_str[j] : 1  

// 1 = 1 
// i = 1 and j = 1
// 2=2

//

/*
        string x_str = to_string(x);
        int i = 0, j = x_str.length() - 1;

        while (i <= j && j >= i) {
            if (x_str[i] == x_str[j]) continue;
            else return false;

            i++;
            j--;
        }

        return true;
*/