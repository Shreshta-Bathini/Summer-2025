#include <vector>
#include <algorithm>
using namespace std;
class Solution {
  public:
    void modifyArray(vector<int>& arr) {
        // code
        int i=0;
        while (i<arr.size()) {
            if (arr[i]!=-1 && arr[i]!=arr[arr[i]])
            swap(arr[i],arr[arr[i]]);
            else
            i++;
        }
    }
};