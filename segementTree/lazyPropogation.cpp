/*
You are given an integer array nums of length n. You need to implement a data structure that efficiently handles the following operations:

Range Sum Query: Given two indices, left and right (0 <= left <= right < n), return the sum of elements in the range [left, right].

Point Update: Update the value of an element at a specific index to a new given value.

Range Increment Update: Given two indices l and r (0 <= l <= r < n) and an integer val, add val to each element in the range [l, r].

The data structure should be optimized to handle multiple queries efficiently, especially for large arrays and ranges.
*/

/*
Time Complexity

1. Construction (NumArray initialization):
   - Time Complexity: O(n)
   - Explanation: Building the segment tree involves initializing each node in the tree based on the input array nums. 
     Since we process each element in the array once while setting up the tree, the total time complexity is O(n).

2. Range Sum Query (sumRange):
   - Time Complexity: O(log n)
   - Explanation: To get the sum of elements in a specific range, we only traverse the relevant segments of the tree, 
     not the entire array. Thanks to the segment tree structure, this traversal takes O(log n) time, even with lazy propagation.

3. Point Update (update):
   - Time Complexity: O(log n)
   - Explanation: Updating a single element in the segment tree requires adjusting values along the path from the root to 
     the target node, affecting at most O(log n) nodes.

4. Range Increment Update (rangeAdd):
   - Time Complexity: O(log n)
   - Explanation: Lazy propagation allows efficient range updates by marking the relevant segments as "lazy" rather than 
     updating every individual element in the range. Only the affected segments are marked, making the update time complexity O(log n).

Space Complexity

1. Segment Tree Array (st):
   - Space Complexity: O(4n)
   - Explanation: The segment tree is implemented using an array of size 4n, allowing us to store and manage nodes for 
     an input array of size n. This extra space ensures each segment and sub-segment has sufficient room.

2. Lazy Propagation Array (lazy):
   - Space Complexity: O(4n)
   - Explanation: The lazy array stores pending updates for each node in the segment tree. Similar to the segment tree, 
     it uses 4n space to accommodate all lazy updates efficiently.

3. Total Space Complexity:
   - Overall Space Complexity: O(n)
   - Explanation: Although the space usage for st and lazy is 4n, it’s effectively O(n) in terms of asymptotic complexity 
     since constants are ignored in Big-O notation.
*/

#include <bits/stdc++.h>
using namespace std;

class NumArray {
private:
    vector<int> st, lazy;
    int n;

    void buildTree(const vector<int>& nums, int node, int lo, int hi) {
        if (lo == hi) {
            st[node] = nums[lo];
        } else {
            int mid = (lo + hi) / 2;
            buildTree(nums, 2 * node + 1, lo, mid);
            buildTree(nums, 2 * node + 2, mid + 1, hi);
            st[node] = st[2 * node + 1] + st[2 * node + 2];
        }
    }

    void applyLazy(int node, int lo, int hi) {
        if (lazy[node] != 0) {
            st[node] += (hi - lo + 1) * lazy[node];
            if (lo != hi) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void rangeUpdate(int node, int lo, int hi, int l, int r, int val) {
        applyLazy(node, lo, hi);
        if (r < lo || l > hi) return;
        if (l <= lo && hi <= r) {
            lazy[node] += val;
            applyLazy(node, lo, hi);
            return;
        }
        int mid = (lo + hi) / 2;
        rangeUpdate(2 * node + 1, lo, mid, l, r, val);
        rangeUpdate(2 * node + 2, mid + 1, hi, l, r, val);
        st[node] = st[2 * node + 1] + st[2 * node + 2];
    }

    int rangeSum(int node, int lo, int hi, int l, int r) {
        applyLazy(node, lo, hi);
        if (l > hi || r < lo) {
            return 0;
        }
        if (l <= lo && hi <= r) {
            return st[node];
        }
        int mid = (lo + hi) / 2;
        int leftSum = rangeSum(2 * node + 1, lo, mid, l, r);
        int rightSum = rangeSum(2 * node + 2, mid + 1, hi, l, r);
        return leftSum + rightSum;
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        st.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
        buildTree(nums, 0, 0, n - 1);
    }

    void update(int index, int val) {
        rangeUpdate(0, 0, n - 1, index, index, val - sumRange(index, index));
    }

    void rangeAdd(int l, int r, int val) {
        rangeUpdate(0, 0, n - 1, l, r, val);
    }

    int sumRange(int left, int right) {
        return rangeSum(0, 0, n - 1, left, right);
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    NumArray numArray(nums);

    cout << "Initial sum of range(1, 3): " << numArray.sumRange(1, 3) << endl;

    numArray.rangeAdd(1, 3, 10);
    cout << "Sum of range(1, 3) after adding 10 to each element: " << numArray.sumRange(1, 3) << endl;

    numArray.update(2, 20);
    cout << "Sum of range(1, 3) after updating index 2 to 20: " << numArray.sumRange(1, 3) << endl;

    return 0;
}

