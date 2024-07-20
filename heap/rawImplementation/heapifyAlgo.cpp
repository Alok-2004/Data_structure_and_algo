#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &nums, int idx) {
    while (true) {
        int left = 2 * idx + 1, right = 2 * idx + 2;
        if (left >= nums.size()) break;
        if (right >= nums.size()) {
            if (nums[idx] > nums[left]) {
                swap(nums[left], nums[idx]);
                idx = left;
            }
            break;
        }
        if (nums[left] < nums[right]) {
            if (nums[idx] > nums[left]) {
                swap(nums[idx], nums[left]);
                idx = left;
            } else break;
        } else {
            if (nums[idx] > nums[right]) {
                swap(nums[idx], nums[right]);
                idx = right;
            } else break;
        }
    }
}

void print(const vector<int> &nums) {
    for (const auto &ele : nums) {
        cout << ele << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = {10, 2, 14, 11, 1, 4};
    print(nums);
    for (int i = nums.size() / 2 - 1; i >= 0; i--) {
        heapify(nums, i);
    }
    print(nums);
    return 0;
}
