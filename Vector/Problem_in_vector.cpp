//Find the last occurrence of x in the vector

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v;
    
    v.push_back(6);
    v.push_back(5);
    v.push_back(4);
    v.push_back(3);
    v.push_back(2);

    int n;
    cout<<"Enter the value to be searched: ";
    cin>>n;
 
    int x = -1;

    for(int i = v.size(); i>=0; i--)
    {
        if(v[i] == n)  
        {   
            x = i;
            break;
        }
    }

    cout<<"Last index of "<<n<<" is "<<x;
    return 0;

}