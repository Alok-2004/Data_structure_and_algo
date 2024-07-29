#include<bits/stdc++.h>
using namespace std;


int minCost(int m, int n, vector<int>& vertical, vector<int>& horizontal) {
    int ans = 0;
    int h = 0;
    int v = 0;
    int hz = 1, vr = 1;
    sort(vertical.begin(), vertical.end(), greater<int>());
    sort(horizontal.begin(), horizontal.end(), greater<int>());

    while (h < horizontal.size() && v < vertical.size()) {
        if (vertical[v] > horizontal[h]) {
            ans += vertical[v] * vr;
            hz++;
            v++;
        } else {
            ans += horizontal[h] * hz;
            vr++;
            h++;
        }
    }

    while (h < horizontal.size()) {
        ans += horizontal[h] * hz;
        h++;
    }

    while (v < vertical.size()) {
        ans += vertical[v] * vr;
        v++;
    }

    return ans;
}

int main(){
    vector<int>vertical = {2, 1, 3, 1, 4};  //cutting cost for x cordinate internal edges
    vector<int>horizontal = {4, 1, 2}; //cutting cost for y cordinate internal edges
    int m = 6, n = 4; //m = size of row and n = size of row
    // total cost = total cost + edge cost * total pieces
    // vertical cut increases horizintal blocks
    // horizontal cut increases vertical blocks

    int res = minCost(m, n, vertical, horizontal);
    cout<<res;
}