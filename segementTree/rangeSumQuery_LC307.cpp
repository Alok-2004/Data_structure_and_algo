/*
307. Range Sum Query - Mutable
Given an integer array nums, handle multiple queries of the following types:

Update the value of an element in nums.
Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
void update(int index, int val) Updates the value of nums[index] to be val.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right 
inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
*/

#inlcude<bits/stdc++.h>
using namespace std;

#include <vector>
using namespace std;

class NumArray {
private:
    vector<int> st;
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

    void updateTree(int node, int lo, int hi, int index, int val) {
        if (lo == hi) {
            st[node] = val;
        } else {
            int mid = (lo + hi) / 2;
            if (index <= mid) {
                updateTree(2 * node + 1, lo, mid, index, val);
            } else {
                updateTree(2 * node + 2, mid + 1, hi, index, val);
            }
            st[node] = st[2 * node + 1] + st[2 * node + 2];
        }
    }

    int rangeSum(int node, int lo, int hi, int l, int r) {
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
        st.resize(4 * n);
        buildTree(nums, 0, 0, n - 1);
    }

    void update(int index, int val) {
        updateTree(0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return rangeSum(0, 0, n - 1, left, right);
    }
};


int main(){
	
}
