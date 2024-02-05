#include<iostream>
using namespace std;

int numOfStairs(int n){
	if( n == 2) return 2; //stair case 
	if( n == 1) return 1;
	if( n == 3) return 4;
	
	return numOfStairs(n-1) + numOfStairs(n-2) + numOfStairs(n-3);
}

int main(){
	int n;
	cout<<"Enter the number of stairs: "<<endl;
	cin>>n;
	
	cout<<numOfStairs(n);
}
