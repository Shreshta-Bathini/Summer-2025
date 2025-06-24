#include <string>
#include <algorithm>
#include <cctype>
using namespace std;
class Solution {
public:
    
        bool isPalindrome(std::string s) {
        // Remove non-alphanumeric characters
        s.erase(std::remove_if(s.begin(), s.end(),
            [](char c) { return !std::isalnum(c); }), s.end());

        // Convert to lowercase
        std::transform(s.begin(), s.end(), s.begin(),
                       [](unsigned char c){ return std::tolower(c); });

        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - 1 - i])
                return false;
        }
        return true;
    }
};
