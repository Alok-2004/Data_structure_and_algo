#include<iostream>
#include<climits>
using namespace std;

/*
int greatest(int arr[], int size, int max, int indx){
	if(indx == size) return max;
	if(arr[indx] > max)  max = arr[indx];
	return greatest(arr, size, max, indx+1);
}

int main(){
	int arr[] = {2, 3 ,4, 6, 7};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	cout<<"Max element: "<<greatest(arr, n, INT_MIN, 0); 
}
*/

int greatest(int arr[], int size, int indx){
	if(indx == size) return INT_MIN;
	return max(arr[indx] , greatest(arr, size, indx + 1));
}

int main(){
	int arr[] = {2, 3 ,4, 6, 7};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	cout<<"Max element: "<<greatest(arr, n, 0);	
}


