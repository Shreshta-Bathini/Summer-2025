#include <vector>
#include <string>
#include <stack>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // Pop two operands
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();

                int result;
                if (token == "+") result = a + b;
                else if (token == "-") result = a - b;
                else if (token == "*") result = a * b;
                else /* token == "/" */ result = a / b;

                s.push(result);
            } else {
                // Token is a number, convert and push
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};
