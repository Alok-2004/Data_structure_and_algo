// total of n-1 swaps will happen

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int arr[] = {3, 1, 4, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i<= n-1; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    int i = 0;
    while(i<n){
        int correct_idx = arr[i] - 1;
        if(i == correct_idx) i++;
        else swap(arr[i], arr[correct_idx]);
    }

    
    for(int i = 0; i<= n-1; i++){
        cout<<arr[i]<<" ";
    }
}