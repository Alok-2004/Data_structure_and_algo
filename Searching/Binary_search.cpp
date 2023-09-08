// Work only if array is sorted either in ascending or descending
// Time complexity in order of logn
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int n = nums.size();
        int mid, lo = 0, hi = n - 1;
        int indx = -1;
        
        while(lo <= hi)
        {
            mid = (lo + hi) / 2;
            if(nums[mid] == target) 
            {
                cout << "Target found.";
                indx = mid;
                return indx;
            }
            else if(nums[mid] > target)
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return indx;
    }
};

int main() {
    Solution solution;
    
    vector<int> nums = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 11;
    
    int result = solution.search(nums, target);
    
    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found." << endl;
    }
    
    return 0;
}

