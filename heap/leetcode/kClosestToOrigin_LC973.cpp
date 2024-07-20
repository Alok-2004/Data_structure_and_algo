#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int , pair<int, int>> pp;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pp>mp;
        
        for(int i = 0; i<points.size(); i++){
            int dis = points[i][0]*points[i][0] + points[i][1] * points[i][1];
            mp.push({dis, {points[i][0], points[i][1]}});
            if(mp.size() > k){ 
                mp.pop();
            }
        }
        vector<vector<int>> res;
        while(!mp.empty()){
            res.push_back({mp.top().second.first, mp.top().second.second});
            mp.pop();
        }
        return res;
    }
};