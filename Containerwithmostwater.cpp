#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& heights) {
        vector<int> solution;
        for (int i=0; i<heights.size(); i++) {
            
            for (int j=0; j<heights.size(); j++) {
                int w=abs(j-i);
                int h;
                if (heights[i]>heights[j])
                 h=heights[j];
                else 
                 h=heights[i];
                
                if (w!=0)
                solution.push_back(w*h);
            }
        }
        sort(solution.begin(),solution.end());
        
        return solution[solution.size()-1];
    }
};
