/*
Problem Statement
You have an array of integers representing the values of coins. 
Two players take turns picking coins from either end of the array. 
The goal is to maximize the value of coins a player can collect. 
The players are both playing optimally, meaning they will make the best possible move at each turn.

Approach
The solution uses Dynamic Programming (DP) to find the optimal strategy. 
The idea is to use a recursive function that considers all possible outcomes and stores the results in a 2D dp table to avoid redundant calculations.
*/

/*
                	  f(0, 3)
                 	/       \
            	3 /          \ 2
            	/             \
        	 f(1, 3)           f(0, 2)
        	 /    \            /     \
    	  9 /      \ 2      3 /       \ 1
    	   /        \        /         \
  		f(2, 3)    f(1, 2)  f(1, 2)     f(0, 1)
   		  /  \       /  \    /\           /  \
 		1/    \2  9/    \1 9/  \1       3/    \9
	    /     \   /     \  /    \       /     \
f(3, 3)   f(2, 2) f(2, 2) f(1, 1)  f(1, 1) f(0, 0)

*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(3005, vector<int>(3005, -1));
vector<int> arr(3005, -1);

int f(int i, int j) {
    if (i == j) return arr[i];
    if (dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = max(arr[i] - f(i + 1, j), arr[j] - f(i, j - 1));
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << f(0, n - 1) << endl;
    return 0;
}

// Bottom up approach
/*
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(3005, vector<int>(3005, 0));
vector<int> arr(3005, 0);

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        dp[i][i] = arr[i];
    }

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = max(arr[i] - dp[i + 1][j], arr[j] - dp[i][j - 1]);
        }
    }

    cout << dp[0][n - 1] << endl;
    return 0;
}
*/

