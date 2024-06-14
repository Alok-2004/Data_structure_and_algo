/*
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>result;
        vector<int> check(nums.size() + 1, false);

        for(int i = 0; i < nums.size(); i++){
            check[nums[i]] = true;
        }

        for(int i = 1; i<check.size(); i++){
            
            if(check[i] == false){
                result.push_back(i);
            }
        }
        return result;
    }
};
having extra space and O(n) as timer complexity
*/

// Now using cyclic sort way
#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> result;
    int n = nums.size();

    int i = 0;
    while( i < n){
        int correct_idx = nums[i] - 1;
        if( nums[correct_idx] == nums[i] || correct_idx == i) i++;
        else swap(nums[i], nums[correct_idx]);
    }

    for(int i= 0; i<nums.size(); i++){
        if(nums[i] != i+1) result.push_back( i + 1);
    }
    return 0;
}
