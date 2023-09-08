// Normal travesal or linear search have time complexity of order of n

#include<iostream>
using namespace std;

int main()
{
	int arr[5] = { 3,2,1,4,5};
	int n = 5;
	bool flag = false;
	for(int i = 0; i<5; i++)
	{
		if(arr[i] == n)
		{
			flag = true;
			break;
		}
	}
	if(flag == true)  cout<<"Element exists in the array.";
	else  cout<<"Element doesnt belong to the array.";
	return 0;		
}
