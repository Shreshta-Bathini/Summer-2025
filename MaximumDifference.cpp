#include <vector>
#include <algorithm>
using namespace std;
class Solution {
  public:
    int findMaxDiff(vector<int> &arr) {
        // code here
        int n = arr.size();
       vector<int> left_smallest(n);
       vector<int> right_smallest(n);
       for (int i=0; i<n; i++) {
           left_smallest[i]=l_s(arr,i);
           right_smallest[i]=r_s(arr,i);
       }
       for (int i=0; i<n; i++) {
           left_smallest[i]=abs(left_smallest[i]-right_smallest[i]);
       }
       sort(left_smallest.begin(),left_smallest.end());
       return left_smallest[n-1];
    

  

    }
    private:
    int l_s(vector<int> p , int i) {
        for (int j=i-1; j>-1; j--) {
            if (p[j]<p[i])
            return p[j];
        }
        return 0;
    }
    int r_s(vector<int> p , int i) {
        for (int j=i+1; j<p.size(); j++) {
            if (p[j]<p[i])
            return p[j];
        }
        return 0;
    }
};