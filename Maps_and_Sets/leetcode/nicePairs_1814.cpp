#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

//Brute force
//TC of n^2
/*
class Solution {
public:
    int rev(int x){
        int r = x;
        int ans = 0;
        while(r > 0){
            int i = r % 10;
            ans = ans * 10 + i;
            r /= 10;
        }
        return ans;
    }

    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i<n ; i++){
            for(int j = i+1; j<n; j++){
                if(nums[i] + rev(nums[j]) == rev(nums[i]) + nums[j])
                    count++;
            }
        }
        return count;   
    }
};
*/

// using hashmap/ unordered maps
class Solution {
public:
    int rev(int x){
        int r = x;
        int ans = 0;
        while(r > 0){
            int i = r % 10;
            ans = ans * 10 + i;
            r /= 10;
        }
        return ans;
    }

    int countNicePairs(vector<int>& nums){
        unordered_map<int, long long>m;
        long long count = 0;
        for(auto ele : nums)  m[ele - rev(ele)]++;
        for (auto &pair : m) 
            if (pair.second >= 2) 
                count += static_cast<long long>((pair.second * (pair.second - 1)) / 2);
                count = count % 1000000007;
        return count % 1000000007;;

    }
};

int main(){
    // sewll wa
}