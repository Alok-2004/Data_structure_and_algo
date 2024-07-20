#include<bits/stdc++.h>
using namespace std;

void heapSort(vector<int> &nums){
    priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
    int i = 0;
    while( !pq.empty() ){
        nums[i] = pq.top();
        pq.pop();
        i++;
    }

    return;
}

int main(){
    vector<int>nums = {9, 7, 5, 3, 2, 1};
    heapSort(nums);
    for(auto ele : nums) cout<<ele<<" ";
    return 0;
}