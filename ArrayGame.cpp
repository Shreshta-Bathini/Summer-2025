#include <vector>
#include <deque>
using namespace std;
class Solution {
  public:
    int min_operations(int n, vector<int>& arr, vector<int>& brr) {
        // code here
        int operations = 0;
        deque<int> d;

        for (int x : arr) {
            d.push_back(x);
        }

        for (int i = 0; i < n; i++) {
            int target = brr[i];

            if (d.front() == target) {
                d.pop_front();
                operations++;
            } else {
                while (d.front() != target) {
                    int front_val = d.front();
                    d.pop_front();
                    d.push_back(front_val);
                    operations++;
                }
                d.pop_front();
                operations++;
            }
        }
        return operations;
    }
};
