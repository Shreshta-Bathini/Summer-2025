#include <stack>
#include <algorithm>
using namespace std;
class MinStack {
    stack<int> p;
public:
    MinStack() {
        
    }
    
    void push(int val) {
       p.push(val);
    }
    
    void pop() {
        p.pop();
    }
    
    int top() {
        return p.top();
    }
    
    int getMin() {
        stack<int> tmp;
        int mini = p.top();
        while (p.size()) {
            mini = min(mini, p.top());
            tmp.push(p.top());
            p.pop();
        }

        while (tmp.size()) {
            p.push(tmp.top());
            tmp.pop();
        }

        return mini;
    }
};
