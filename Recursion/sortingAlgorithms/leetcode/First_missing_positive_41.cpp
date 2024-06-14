// Important for interview 
#include <iostream>
#include <vector>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    while(i < n){
        if(nums[i] <= 0) i++;
        else if(nums[i] <= 0 || nums[i] > n || nums[i] == i + 1 || nums[nums[i] - 1] == nums[i]) i++;
        else swap(nums[i], nums[nums[i] - 1]);
    }

    for(int i = 0; i<nums.size(); i++){
        if(i+1 != nums[i]){
            return i+1;
        }
    }

    return n + 1;
}

int main() {
    vector<int> nums = {3, 4, -1, 1};
    cout << "The smallest positive integer missing is: " << firstMissingPositive(nums) << endl;

    return 0;
}
