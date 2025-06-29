#include <iostream>
#include <queue>
using namespace std;
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 
void QueueStack ::push(int x) {
    // code here
    if (q1.empty()) {
    q1.push(x); 
        while (!q2.empty()) {
            int val = q2.front();
            q2.pop();
            q1.push(val);
        }
    }
    else if (q2.empty()) {
        q2.push(x); 
        while (!q1.empty()) {
            int val = q1.front();
            q1.pop();
            q2.push(val);
        }
    }
    
}

int QueueStack ::pop() {

    
    // code here
    if (!q1.empty()) {
        int val = q1.front();
        q1.pop();
        return val;
    }
    else if (!q2.empty()) {
        int val = q2.front();
        q2.pop();
        return val;
    }
    
    return -1;
}