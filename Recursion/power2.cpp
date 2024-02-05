//logarithmic, Time complexity O(logn)
#include<iostream>
using namespace std;

int pow(int b, int e){
	if(e == 1) return b;
	int ans = pow(b, e/2);
	if(e%2 == 0){
		return ans * ans;	
	}else{
		return ans * ans * b;
	}
}

int main(){
	int e;
	cin>>e;
	 
	cout<<pow(3,e);	
}
