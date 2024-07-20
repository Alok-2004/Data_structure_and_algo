/*
632. Smallest Range Covering Elements from K Lists
You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
*/

// time complexity O(nKlogK)

#include<bits/stdc++.h>
using namespace std;

auto init = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

typedef pair<int, pair<int, int>>  pip;


class Solution {
public:
    vector<int> smallestRange(vector<vector<int> > &nums) {
        priority_queue<pip, vector<pip>, greater<pip> > pq; //minheap containing value, pair<i, j>
        int mx = INT_MIN;

        for(int i = 0; i<nums.size(); i++){
            mx = max(mx, nums[i][0]);
            pq.push({ nums[i][0], {i, 0}});
        }

        int mn = pq.top().first;
        int start = mn, end = mx;

        while(true){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(col == nums[row].size() - 1) break;
            pq.push({ nums[row][col+1] , {row, col + 1}});
            mx = max(mx, nums[row][col + 1] );
            mn = pq.top().first;
            if( (mx-mn) < (end - start) ){
                end = mx;
                start = mn;
            }
        }

        vector<int>res(2, 0);
        res[0] = start;
        res[1] = end;

        return res;
    }
};
