#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> nums(5);

    // Input phase
    for(int i = 0; i < 5; i++)
    {
        cin >> nums[i];
    }

    int n = 5;

    // Display input
    for(int ele : nums)
    {
        cout << ele << " ";
    }
    cout << endl;

    // Insertion sort
    for(int i = 1; i < n; i++) // Start from the second element
    {
        int j = i;
        /*
        or
        while(j>=1)
        {
            if(nums[j] > nums[j-1])  break;
            else  swap(nums[j],nums[j-1]);
            j--;
        }
        */
        while(j > 0 && nums[j] < nums[j - 1]) // Move the current element to its correct position 
        {// Make sure to use j>0 other wise it will error
            swap(nums[j], nums[j - 1]);
            j--;
        }
    }

    // Display sorted result
    for(int ele : nums)
    {
        cout << ele << " ";
    }

    return 0;
}