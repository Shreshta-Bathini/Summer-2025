#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWays(int N, int r, vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;
        vector<int> current_combination;

        findCombination(arr, r, 0, current_combination, result);
        return result;
    }
private:
    void findCombination(vector<int>& arr, int r, int start_index, vector<int> current_combination, vector<vector<int>>& result) {
        if (current_combination.size() == r) {
            result.push_back(current_combination);
            return;
        }
        if (start_index == arr.size())
            return;

        for (int i = start_index; i < arr.size(); i++) {
            current_combination.push_back(arr[i]);
            findCombination(arr, r, i + 1, current_combination, result);
            current_combination.pop_back();

            while (i + 1 < arr.size() && arr[i] == arr[i + 1]) {
                i++;
            }
        }
    }
};

int main() {
    int N, r;
    cout << "Enter number of elements (N): ";
    cin >> N;
    vector<int> arr(N);
    cout << "Enter the elements:\n";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cout << "Enter size of combinations (r): ";
    cin >> r;

    Solution sol;
    vector<vector<int>> combinations = sol.findWays(N, r, arr);

    cout << "Combinations of size " << r << " are:\n";
    for (auto &combo : combinations) {
        for (int val : combo) {
            cout << val << " ";
        }
        cout << "\n";
    }
    return 0;
}
