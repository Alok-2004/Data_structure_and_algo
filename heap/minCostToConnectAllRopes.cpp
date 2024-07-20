#include<bits/stdc++.h>
using namespace std;

int minCost(vector<int>& nums){
    priority_queue<int, vector<int>, greater<int> > pq; //min heap
    int res = 0;
    for(auto ele : nums){
        pq.push(ele);
    }
    while(pq.size() > 1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a + b);
        res += a + b;
    }

    return res; 
}

int main(){
    vector<int> nums = {2, 7, 4, 1, 8};
    int res = minCost(nums);
    cout<<res;
    return 0;
}