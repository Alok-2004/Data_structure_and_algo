#include<bits/stdc++.h>
using namespace std;

/*
Time Complexity : O(nlogk)
Auxilliary Space : O(n)
*/

class Solution{
    public:
    vector <int> nearlySorted(int arr[], int n, int k){
        priority_queue<int, vector<int>, greater<int> >pq; // min heap
        vector<int> res;
        for(int i = 0 ; i<n; i++){
            pq.push(arr[i]);
            if(pq.size() > k){
                res.push_back(pq.top());
                pq.pop();
            }
        }
        while(pq.size() > 0){
            res.push_back(pq.top());
            pq.pop();
        }

        return res;

    }  
};
