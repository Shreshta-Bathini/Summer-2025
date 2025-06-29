#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool wifiRange(int N, string S, int X) {
        // code here
        vector<int> index;
        for (int i = 0; i < N; i++) {
            if (S[i] == '1')
                index.push_back(i);
        }
        if (index.empty())
            return false;
        for (int i = 1; i < index.size(); i++) {
            if (index[i] - index[i - 1] > (2 * X + 1))
                return false;
        }
        if (index[0] - X > 0)
            return false;
        if (index.back() + X < N - 1)
            return false;
        return true;
    }
};
