/*
Description
The problem involves finding the minimum cost of merging colors in a sequence. 
Each merge operation has a cost proportional to the sum of the colors being merged. 
The task is to compute the minimum possible cost to merge all colors into one. 
The solution uses dynamic programming to optimize the process.
*/

//https://www.spoj.com/problems/MIXTURES/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<vector<ll>> dp[105][105];

ll solve(vector<int>& colors, int i, int j) {
    ll result = 0;
    for (int m = i; m <= j; m++) {
        result = (result + colors[m]) % 100;
    }
    return result;
}

ll helper(vector<int>& colors, int i, int j) {
    if (i == j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    ll result = LLONG_MAX;
    for (int k = i; k < j; k++) {
        result = min(result, helper(colors, i, k) + helper(colors, k + 1, j) + solve(colors, i, k) * solve(colors, k + 1, j));
    }

    return dp[i][j] = result;
}

int main() {
    int n;
    while (cin >> n) {
        vector<int> colors(n);
        for (int i = 0; i < n; i++) {
            cin >> colors[i];
        }

        memset(dp, -1, sizeof(dp));

        cout << helper(colors, 0, n - 1) << endl;
    }

    return 0;
}

