#include<iostream>
#include<vector>

using namespace std;

void display(vector<int>&a)
{
	for(int i = 0; i<a.size(); i++)
	{
		cout<<a[i]<<" ";
	}
	
	return;
}

int main()
{
    vector<int>arr;
    arr.push_back(1);
    arr.push_back(3);
    arr.push_back(5);
    arr.push_back(10);
    arr.push_back(5);
    arr.push_back(8);

    display(arr);
    cout<<endl;

    /*int i =0;
    int j = arr.size() - 1;
    while(i<=j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }*/

    // for(int i = 0,int j = arr.size() - 1; i<=j; i++,j--)
    // {
    //     int temp = arr[i];
    //     arr[i] = arr[j];
    //     arr[j] = temp;
    // }

    reverse(arr.begin(),arr.end());


    display(arr);
    return 0;

}