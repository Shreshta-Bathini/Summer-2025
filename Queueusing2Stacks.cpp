#include <stack>
using namespace std;

class StackQueue {
private:
    stack<int> s1;
    stack<int> s2;

public:
    void push(int B) {
        if (s1.empty()) {
            s1.push(B);
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
        else if (s2.empty()) {
            s2.push(B);
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }

    int pop() {
        if (!s1.empty()) {
            int val = s1.top();
            s1.pop();
            return val;
        }
        else if (!s2.empty()) {
            int val = s2.top();
            s2.pop();
            return val;
        }
        return -1;  // Queue is empty
    }

    // Reset the internal stacks to clear previous test case data
    void reset() {
        while (!s1.empty()) s1.pop();
        while (!s2.empty()) s2.pop();
    }
};
