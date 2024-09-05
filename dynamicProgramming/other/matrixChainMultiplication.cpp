//Matric chain Multiplication

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int helper(int i, int j, vector<int>& arr) {
    if (i == j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int ans = INT_MAX;
    for (int k = i; k < j; k++) {
        ans = min(ans, helper(i, k, arr) + helper(k + 1, j, arr) + arr[i - 1] * arr[k] * arr[j]);
    }
    return dp[i][j] = ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    dp.resize(n, vector<int>(n, -1));
    cout << helper(1, n - 1, v) << "\n";
    return 0;
}

