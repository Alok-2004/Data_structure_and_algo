#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int> nums = {4, 1, 8, 2, 6, 3, 7};
    int n = nums.size();
    int sum = (n * (n - 1)) / 2;
    int actual_Sum = 0;
    for (int num : nums) {
        actual_Sum += num;
    }
    cout<<actual_Sum - sum;
}

/*
int findDuplicate(vector<int>& nums) {
    int i = 0;
    while (i < nums.size()) {
        if (nums[i] != i + 1) {
            if (nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            } else {
                return nums[i];
            }
        } else {
            i++;
        }
    }
    return -1; // No duplicate found
}
*/