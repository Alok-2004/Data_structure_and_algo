#include<bits/stdc++.h>
using namespace std;

/*
Expected Time Complexity : O(NlogN)
Expected Auxilliary Space : O(N)
*/

class Solution {
public:
    typedef pair<int, int> p1;  // now where we will write p1 pair<int, int> will be replaced
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        for(auto ele : nums)  mp[ele]++;

        //heap pair is <fre, ele>
        priority_queue<p1, vector<p1>, greater<p1>>pq;

        for(auto x : mp){
            int ele = x.first, freq = x.second;
            pq.push({freq, ele});
            if(pq.size() > k)  pq.pop();
        } 

        vector<int>res;
        while(pq.size() > 0){
            int ele = pq.top().second;
            res.push_back(ele);
            pq.pop();
        }

        return res;
    }
};