/*
value/weight should be max
*/
#include <bits/stdc++.h>
using namespace std;

bool customComparator(pair<int, int> &p1, pair<int, int> &p2) {
    double r1 = (p1.first * 1.0) / (p1.second * 1.0);
    double r2 = (p2.first * 1.0) / (p2.second * 1.0);
    return r1 > r2;
}

double fractionalKnapsack(vector<int> &profit, vector<int> &weight, int n, int W) {
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++) {
        arr.push_back({profit[i], weight[i]});
    }

    sort(arr.begin(), arr.end(), customComparator);
    double prof = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].second <= W) {
            prof += arr[i].first;
            W -= arr[i].second;
            cout<<arr[i].second<<endl;
        } else {
            prof += ((arr[i].first * 1.0) / (arr[i].second * 1.0)) * W;
            W = 0;
            cout<<arr[i].second<<endl;
            break;
        }
    }
    return prof;
}

int main() {
    vector<int> profit = {69, 100, 120};
    vector<int> weights = {10, 20, 30};
    int W = 50; // max weight
    int n = 3;
    double res = fractionalKnapsack(profit, weights, n, W);
    cout << "Maximum profit: " << res << endl;
    return 0;
}
