#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> p;
        for ( char c : s) {
            if (c == '{' || c == '(' || c == '[') p.push(c);
            if (c == '}'|| c == ')' || c == ']') {
                if (p.empty()) return false;
                if (c - p.top() != 1 && c - p.top() != 2) return false;
                p.pop();
            }
        }
        if (p.empty()) return true;
        return false;
    }
};