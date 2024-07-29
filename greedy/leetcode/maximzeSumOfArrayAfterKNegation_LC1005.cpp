/*
1005. Maximize Sum Of Array After K Negations
Given an integer array nums and an integer k, modify the array in the following way:

choose an index i and replace nums[i] with -nums[i].
You should apply this process exactly k times. You may choose the same index i multiple times.

Return the largest possible sum of the array after modifying it in this way.
*/

#include<bits/stdc++.h>
using namespace std;

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int res = 0;
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        
        for(int i = 0 ; i < nums.size() ; i++) res += nums[i];

        while( k-- ){
            if(pq.top() == 0)  break;
            int t = pq.top();
            res -= t;
            pq.pop();
            t = -t;

            res = res + t;

            pq.push(t);
        }
        return res;
    }
};

/*
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        int i=0 , sum=0;

        while(i<nums.size() && nums[i]<0 && k)
        {
            k--;
            nums[i]=0-nums[i];
            i++;
        }
        sort(nums.begin(),nums.end());
        if(k>0 && k%2!=0)
            nums[0]=0-nums[0];

        for(i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        return sum;

    }
};
*/

int main(){
    vector<int>nums = {2, 1, 3, 4};
    int k = 3;
    Solution s;
    int res = s.largestSumAfterKNegations(nums, k);
    cout<<res;
}