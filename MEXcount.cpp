#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        vector<int> freq(n + 2, 0);  // because a[i] ≤ n
        for (int x : a) {
            freq[x]++;
        }

        vector<int> possible(n + 1, 0);  // possible[k] = how many MEX values possible after removing k elements

        int need = 0;  // total elements we need to keep (from 0 to mex-1)
        for (int mex = 0; mex <= n; ++mex) {
            if (mex > 0 && freq[mex - 1] == 0) {
                break;  // can't form this MEX because a value < mex is missing
            }

            int removals_needed = freq[mex];  // to make `mex` missing
            if (removals_needed + need <= n) {
                possible[removals_needed]++;
            }

            need += freq[mex];
        }

        // prefix sum to count how many MEX values are possible for each k
        int total = 0;
        for (int k = 0; k <= n; ++k) {
            total += possible[k];
            cout << total << " ";
        }
        cout << "\n";
    }

    return 0;
}
