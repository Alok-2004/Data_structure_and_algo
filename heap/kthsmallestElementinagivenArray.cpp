#include<bits/stdc++.h>
using namespace std;

// Method - 1: sort, TC = depends on sorting algo, SC = O(logn)
// Method - 2: uaing heap TC = O(n.logk), SC= O(n)

int main(){
    vector<int> arr = {101, 20, -4, 6, 18, 24, 105, 118};
    int k = 3;
    priority_queue<int>pq;
    for(auto ele : arr){
        pq.push(ele);
        if(pq.size() > k) pq.pop();
    }
    int res = pq.top();
    cout<<res;
    return 0;
}