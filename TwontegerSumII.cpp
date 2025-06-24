#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> solution;
        
        for (int i=0; i<numbers.size(); i++) {
            if (numbers[i]<=target/2) {
                for (int j=i+1; j<numbers.size(); j++) {
                    if (numbers[i]+numbers[j]==target&&numbers[i]!=numbers[j]) {
                        solution.push_back(i+1);
                        solution.push_back(j+1);
                        return solution;
                    }
                }
            }
        }
    }
};