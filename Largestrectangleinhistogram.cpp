#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> result;
        for (int i=0; i<heights.size(); i++) {
            int p = heights[i];
            vector<int> y = max_count(heights);
            result.push_back(p*y[i]);
        }
        sort(result.begin(),result.end());
        return result[result.size()-1];
    }
private :
   vector<int> max_count (vector<int> s) {
    vector<int> store;
    for (int h=0; h<s.size(); h++) {
        int n=s[h];
        int count = 0;
        for (int k=h-1; k>=0; k-- ) {
            if (s[k]>=n)
            count++;
            else 
            break;
        }
        for (int k=h+1; k<s.size(); k++) {
        if (s[k]>=n)
        count++;
        else
        break;
    }
    store.push_back(count+1);
   }  
   return store;  
}
};
