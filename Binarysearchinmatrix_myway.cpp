#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto x : matrix) {
            int low = 0; 
            int high = x.size() -1;
            while (low<=high) {
                int mid = (low+high)/2;
                if (target==x[mid])
                return true;
                else if (target>x[mid])
                low=mid+1;
                else if (target<x[mid])
                high=mid-1;
            }
        }
        return false;
    }
};
