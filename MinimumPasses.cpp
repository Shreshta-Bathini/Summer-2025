#include <vector>
#include <algorithm>
using namespace std;
class Solution {
  public:
    int minPass(int n, vector<int>& height) {
        // code here

        int count = 0;

        while (!is_sorted(height.begin(), height.end())) {
            if (height.size() <= 1)
                break;

            count++;

            vector<int> new_height;

            if (!height.empty())
                new_height.push_back(height[0]);

            for (size_t i = 1; i < height.size(); i++) {
                if (height[i] > height[i - 1]) {
                    new_height.push_back(height[i]);
                }
            }

            if (new_height.size() == height.size() && 
                !is_sorted(new_height.begin(), new_height.end())) {
                break;
            }

            height = new_height;
        }

        return count;
    }
};
