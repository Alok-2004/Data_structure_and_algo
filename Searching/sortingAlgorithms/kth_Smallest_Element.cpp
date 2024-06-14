//WAP to find Kth samllest element in an array using QuickSort

// TC with merge sort is O(nlogn)but with Quick Select(variation of QuickSort) is O(n) on average
// but with Selecction sort, Bubble, Insertion sort TC is O(n*k)

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int partition(vector<int> &v, int starting_idx, int last_idx){
    int pivot_idx = starting_idx;
    int i = starting_idx + 1;
    int j = last_idx;
    while(i <= j){
        if( v[i] <= v[pivot_idx])  i++;
        else if(v[j] > v[pivot_idx]) j--;
        else{
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }

    swap(v[j], v[starting_idx]);
    pivot_idx = starting_idx + j;
    return pivot_idx;
}

int KthSmallestIndex(vector<int> &v, int starting_idx, int last_idx, int k){
    int partition_idx = partition(v, starting_idx, last_idx);
    if(partition_idx + 1 == k)  return v[partition_idx];
    else if(partition_idx < k) return KthSmallestIndex(v, partition_idx + 1, last_idx, k);
    else  return KthSmallestIndex(v, starting_idx, partition_idx - 1, k);
}


int main(){
    int arr[] = {2, 4, 1, 7, 5, 9, 8};
    int number_of_elements = sizeof(arr) / sizeof(arr[0]);

    vector<int > v(arr, arr + number_of_elements);

    cout<<"Original Array: "<<endl;
    for(int i = 0; i < v.size() - 1; i++){
        cout<<v[i]<<" ";
    }

    cout<<endl;
    cout<<"Enter the value of K: ";
    int k;
    cin>>k;

    int element = KthSmallestIndex(v, 0, v.size() - 1, k);
    cout<<element;
    return 0;
}