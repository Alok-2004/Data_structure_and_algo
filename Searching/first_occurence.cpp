// Given sorted array of n elements and a target 'x'.
//Find the first occurence of 'x' in the array.
//If 'x' doesnt exists then return -1.

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(4);
    nums.push_back(5);

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
        	if(nums[mid - 1] != target)
        	{
        		flag = true;
        		cout<<mid;
        		break;
			}
            else
            {
            	hi = mid - 1;
			}
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
        if (hi < 0)  cout << "No smaller element found";
        else  cout << nums[hi];
    }

    return 0;
}

