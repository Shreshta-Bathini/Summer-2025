#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
  public:
    queue<int> modifyQueue(queue<int> &q, int k) {
        // code here
        vector<int> arr;
        while (!q.empty()) {
            
            
            arr.push_back(q.front());
            q.pop();
            
        }
        reverse(arr.begin(),arr.begin()+k);
        for (int i : arr ){
            q.push(i);
        }
        return q;
    }
};
