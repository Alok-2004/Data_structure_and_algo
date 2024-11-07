/*
2080. Range Frequency Queries
Design a data structure to find the frequency of a given value in a given subarray.

The frequency of a value in a subarray is the number of occurrences of that value in the subarray.

Implement the RangeFreqQuery class:

RangeFreqQuery(int[] arr) Constructs an instance of the class with the given 0-indexed integer array arr.
int query(int left, int right, int value) Returns the frequency of value in the subarray arr[left...right].
A subarray is a contiguous sequence of elements within an array. arr[left...right] denotes the subarray that 
contains the elements of nums between indices left and right (inclusive).
*/
 
#include<bits/stdc++.h>
using namespace std;

class RangeFreqQuery {
private:
    vector<unordered_map<int, int>> segTree;
    int n;

    void buildTree(const vector<int>& arr, int node, int lo, int hi) {
        if (lo == hi) {
            segTree[node][arr[lo]]++;
        } else {
            int mid = (lo + hi) / 2;
            buildTree(arr, 2 * node + 1, lo, mid);
            buildTree(arr, 2 * node + 2, mid + 1, hi);
            for (const auto& [key, val] : segTree[2 * node + 1]) {
                segTree[node][key] += val;
            }
            for (const auto& [key, val] : segTree[2 * node + 2]) {
                segTree[node][key] += val;
            }
        }
    }

    int rangeQuery(int node, int lo, int hi, int l, int r, int value) {
        if (lo > r || hi < l) {
            return 0;
        }
        if (l <= lo && hi <= r) {
            return segTree[node][value];
        }
        int mid = (lo + hi) / 2;
        int leftFreq = rangeQuery(2 * node + 1, lo, mid, l, r, value);
        int rightFreq = rangeQuery(2 * node + 2, mid + 1, hi, l, r, value);
        return leftFreq + rightFreq;
    }

public:
    RangeFreqQuery(vector<int>& arr) {
        n = arr.size();
        segTree.resize(4 * n);
        buildTree(arr, 0, 0, n - 1);
    }
    
    int query(int left, int right, int value) {
        return rangeQuery(0, 0, n - 1, left, right, value);
    }
};


int main(){
	
}
