// But also maintain relative order

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(0);
	nums.push_back(4);
	nums.push_back(0);
	nums.push_back(5);
	
	int n = nums.size();
	
	for(int i = 0; i<n; i++)
	{
		cout<<nums[i]<<" ";
	}
	cout<<endl;
	
	for(int i = 0; i<n-1; i++)
	{
		for(int j = 0; j<n-1-i; j++)
		{
			if(nums[j] == 0)
			{
				swap(nums[j], nums[j+1]);
			}
		}
	}
	
	for(int i = 0; i<n; i++)
	{
		cout<<nums[i]<<" ";
	}
	return 0;
}
