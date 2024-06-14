#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int> &v, int starting_idx, int last_idx){
    int pivot_Element = v[starting_idx];
    int i = starting_idx + 1;
    int j = last_idx;

    while(i <= j) {
        if(v[i] <= pivot_Element)   i++;
        else if(v[j] > pivot_Element)  j--;
        else {
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }

    int pivot_indx = j;
    swap(v[starting_idx], v[pivot_indx]);
    return pivot_indx;
}
/*
    int pivot_Element = v[(starting_idx + last_indx) / 2];
    int count = 0;
    for(int i = starting_idx; i <= last_idx; i++){
        if(i == (startinf_idx + last_idx) / 2) continue;
        if(arr[i] <= pivot_Element) count++;
    }

    int pivot_idx = count + starting_idx;
    swap(arr[starting_idx], arr[pivot_idx]);

*/
void quickSort(vector<int> &v, int starting_idx, int last_idx){
    if(starting_idx >= last_idx)    return;  // base case
    
    int pivot_indx = partition(v, starting_idx, last_idx);

    quickSort(v, starting_idx, pivot_indx - 1);
    quickSort(v, pivot_indx + 1, last_idx);
}

int main(){
    int arr[] = {5, 1, 8, 2, 7, 6, 3, 4, 12, -1};
    int n = sizeof(arr) / sizeof(arr[0]);

    for(int  i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    vector<int> v(arr, arr + n);
    quickSort(v, 0, n-1);  //quickSort(array, Starting index, last index)
    
    cout<<"Sorted array: "<<endl;
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}
