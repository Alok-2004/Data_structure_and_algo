#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(9);
    nums.push_back(10);

    int target;
    cin >> target;
    int n = nums.size();
    int mid, lo = 0, hi = n - 1;
    bool flag = false;
    
    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;
        if (nums[mid] == target)
        {
            flag = true;
            cout << nums[mid - 1];
            break;
        }
        else if (nums[mid] > target)
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1; 
        }
    }

    if (flag == false)
    {
        if (hi < 0)
        {
            cout << "No smaller element found";
        }
        else
        {
            cout << nums[hi];
        }
    }

    return 0;
}

