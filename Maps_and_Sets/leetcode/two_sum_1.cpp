#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;


// TC of )(n^2)
// class Solution 
// {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) 
// 	{
//   for(int i = 0; i<nums.size(); i++)
// 	{
// 		for(int j = i+1; j<nums.size(); j++)
// 		{
// 			if(nums[j] + nums[i] == target)
// 			{
// 				return {i,j};
// 			}
// 		}
// 	}
// 	return {};
// }
// }

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>m;
        vector<int> ans(2, 0);

        for(int i = 0; i<nums.size(); i++){
            int diff = target - nums[i]; 
            if( m.find(diff) != m.end()){
                ans[1] = m[ans[diff]];
                ans[0] = i;
                break;
            }else   m[nums[i]] = i;
        }
        return ans;
    }
};