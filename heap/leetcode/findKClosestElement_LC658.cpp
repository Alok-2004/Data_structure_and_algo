#include<bits/stdc++.h>
using namespace std;

// using Priority Queues
class Solution {
public:

    typedef pair<int, int> pp;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // k is number of ele
        // x used for references

        priority_queue<pp>mp; // difference, ele

        for(auto ele : arr){
            int diff = abs(ele-x);
            mp.push({diff, ele});
            if(mp.size() > k){ 
                mp.pop();
            }
        }
        vector<int> res;
        while(!mp.empty()){
            res.push_back(mp.top().second);
            mp.pop();
        }

        sort(res.begin(), res.end());
        return res;
    }
};