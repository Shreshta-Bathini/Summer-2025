#include <vector>
#include <stack>
using namespace std;
class Solution {
  public:
    int SaveGotham(vector<int>& arr) {
        int n = arr.size();
        int mod = 1000000007;
        stack<int> s;

        int ans = 0;
        // push the first element to stack
        s.push(arr[0]);

        // iterate for rest of the elements
        for (int i = 1; i < n; i++) {

            if (s.empty()) {
                s.push(arr[i]);
                continue;
            }

            /* if stack is not empty, then
               pop an element from stack.
               If the popped element is smaller
               than next, then
            a) print the pair
            b) keep popping while elements are
            smaller and stack is not empty */
            while (s.empty() == false && s.top() < arr[i]) {
                // cout << s.top() << " --> " << arr[i] << endl;
                ans = (ans + arr[i]) % mod;
                s.pop();
            }

            /* push next to stack so that we can find
            next greater for it */
            s.push(arr[i]);
        }

        return ans;
    }
};