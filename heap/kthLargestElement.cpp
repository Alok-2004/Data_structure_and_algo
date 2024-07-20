#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {101, 20, -4, 6, 18, 24, 105, 118};
    int k = 3;
    priority_queue<int, vector<int>, greater<int>> pq; //min heap
    for(auto ele : arr){
        pq.push(ele);
        if(pq.size() > k) pq.pop();
    }
    int res = pq.top();
    cout<<res;
    return 0;
}