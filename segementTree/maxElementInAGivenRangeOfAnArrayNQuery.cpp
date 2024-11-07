// MAx Element in a Given Range of an Array
// Basic of bulding Segment Tree and Searching 

#include <bits/stdc++.h>
using namespace std;

vector<int> st;

void buildTree(int arr[], int node, int lo, int hi) {
    if (lo == hi) {
        st[node] = arr[lo];
    } else {
        int mid = (lo + hi) / 2;
        buildTree(arr, 2 * node + 1, lo, mid); // Left subtree
        buildTree(arr, 2 * node + 2, mid + 1, hi); // Right subtree
        st[node] = max(st[2 * node + 1], st[2 * node + 2]); // Store max value
    }
}

int getMax(int node, int lo, int hi, int l, int r) {
    if (l > hi || r < lo) {
        return INT_MIN; // Out of range
    }
    if (l <= lo && r >= hi) {
        return st[node]; // Current segment is fully within range
    }
    int mid = (lo + hi) / 2;
    int leftMax = getMax(2 * node + 1, lo, mid, l, r); // Query left child
    int rightMax = getMax(2 * node + 2, mid + 1, hi, l, r); // Query right child
    return max(leftMax, rightMax); // Return the maximum value found
}

int main() {
    int arr[] = {1, 4, 2, 8, 6, 4, 9, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    st.resize(4 * n);
    buildTree(arr, 0, 0, n - 1);
    
    int l, r;
    cout << "Enter the range (l and r): ";
    cin >> l >> r;
    cout << "Maximum value in range [" << l << ", " << r << "] is " << getMax(0, 0, n - 1, l, r) << endl;
    return 0;
}

