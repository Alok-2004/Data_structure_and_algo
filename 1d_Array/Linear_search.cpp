//Linear search

// Searching for elements
/*
#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the Size of array: ";


    cin>>n;

    int x;
    cout<<"Enter the number for which you want to search: ";
    cin>>x;

    int arr[n];
    for(int i = 0; i<=n-1;i++)
    {
        cin>>arr[i];
    }

    bool flag = false;

    for(int i = 0; i<=n-1; i++)
    {
        if(arr[i]==x)  flag == true;
    }

    if(flag = true) cout<<"Element found.";
    
    else cout<<"Not found";

    return 0;
}
*/

// Finding Max element
/*
#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the Size of array: ";
    cin>>n;

    int arr[n];
    for(int i = 0; i<=n-1;i++)
    {
        cin>>arr[i];
    }
    
    int max = arr[0];
    for(int i = 0; i<=n-1; i++)
    {
        if(max<arr[i])  max = arr[i];
    }
    cout<<max;
    return 0;
}
*/

//Second max

#include<iostream>
#include<climits>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the Size of array: ";
    cin>>n;


    int arr[n];
    for(int i = 0; i<=n-1;i++)
    {
        cin>>arr[i];
    }
    
    int max = INT_MIN;
    for(int i = 0; i<=n-1; i++)
    {
        if(max<arr[i])  max = arr[i];
    }
    
    int nd_max = INT_MIN;
    for(int i = 0; i<=n-1; i++)
    {
        if(arr[i] != max && nd_max<arr[i])   nd_max = arr[i];
    }


    cout<<nd_max;
    return 0;
}

//number of elements bigger then the given number in array