#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto ele : stones){
            pq.push(ele);
        }

        while(pq.size() > 1){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();

            int diff = x - y;
            if(diff > 0) pq.push(diff);
            else if(diff < 0) pq.push(abs(diff));
        }
        if(!pq.empty()) pq.top();
        else return 0;
    }
};

// OR
// class Solution {
// public:
//     int lastStoneWeight(vector<int>& arr) {
//         while(arr.size()>1){
//             sort(arr.begin(),arr.end());
//             int x = arr[arr.size()-1];
//             arr.pop_back();
//             int y = arr[arr.size()-1];
//             arr.pop_back();
//             if(x!=y) arr.push_back(x-y);
//         }
//         if(arr.size()) return arr[0];
//         else return 0;
//     }
// };