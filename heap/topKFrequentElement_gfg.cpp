#include<bits/stdc++.h>
using namespace std;

/*
Expected Time Complexity : O(NlogN)
Expected Auxilliary Space : O(N)
*/
// M1 uisng priority queue

class Solution {
public:
    typedef pair<int, int> p1;
    
    vector<int> topK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto ele : nums)  
            mp[ele]++;
        
        auto comp = [](const p1& a, const p1& b) {
            if(a.first == b.first) 
                return a.second < b.second;
            else return a.first > b.first;
        };

        priority_queue<p1, vector<p1>, decltype(comp)> pq(comp);

        for(auto x : mp){
            int ele = x.first, freq = x.second;
            pq.push({freq, ele});
            if(pq.size() > k)  
                pq.pop();
        } 

        vector<int> res;
        while(!pq.empty()){
            int ele = pq.top().second;
            res.push_back(ele);
            pq.pop();
        }
        
        return res;
    }
};