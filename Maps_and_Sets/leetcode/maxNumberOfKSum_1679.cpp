#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int count = 0;
        for(auto x : nums){
            int diff = k - x;
            if(mp[diff] > 0) {
                count++;
                mp[diff]--;
            } else {
                mp[x]++;
            }
        }
        return count;
    }
};
