#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string solve(vector<int>& a) {
    int n = a.size();
    vector<int> left_min(n), right_max(n);
    
    left_min[0] = a[0];
    for (int i = 1; i < n; i++)
        left_min[i] = min(left_min[i-1], a[i]);

    right_max[n-1] = a[n-1];
    for (int i = n - 2; i >= 0; i--)
        right_max[i] = max(right_max[i+1], a[i]);

    string result;
    for (int i = 0; i < n; i++) {
        if (left_min[i] == a[i] || right_max[i] == a[i])
            result += '1';
        else
            result += '0';
    }

    return result;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << solve(a) << '\n';
    }
    return 0;
}
