#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> nums(5);
	for(int i = 0; i<5; i++)
	{
		cin>>nums[i];
	}
	
	sort(nums.begin(), nums.end()); // T.O in order of nlogn and also the best
	
	for(int i = 0; i<5; i++)
	{
		cout<<nums[i]<<" ";
	}
	
}
