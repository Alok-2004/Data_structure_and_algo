/*

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

void quickSort(vector<int> &v, int starting_idx, int last_idx){
    if( starting_idx >=  last_idx) return;
    int pivot_idx = partition(v, starting_idx, last_idx);

    quickSort(v, 0, pivot_idx - 1);
    quickSort(v, pivot_idx + 1, last_idx);

}

int main(){
    int arr[] = {2, 4, 1, 7, 5, 9, 8};
    int number_of_elements = sizeof(arr) / sizeof(arr[0]);

    vector<int > v(arr, arr + number_of_elements);

    cout<<"Original Array: "<<endl;
    for(int i = 0; i < v.size() - 1; i++){
        cout<<v[i]<<" ";
    }

    quickSort(v, 0, v.size() - 1); // quickSort(vector<int> v, starting_index, ending_index);

    cout<<"Sorted Array: "<<endl;

    for(int i = 0; i < v.size() - 1; i++){
        cout<<v[i]<<" ";
    }

    return 0;
}

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int partition(vector<int> &v, int starting_idx, int last_idx){
    int pivot_idx = starting_idx;
    int i = starting_idx + 1;
    int j = last_idx;
    while( j >= i ){
        if(v[i] <= v[pivot_idx])  i++;
        else if( v[j] > v[pivot_idx] ) j--;
        else{
            swap(v[i], v[j]);
            i++;
            j--;
        }
    }

    swap(v[j], v[pivot_idx]);
    pivot_idx = j;
    return pivot_idx;
}


void quickSort(vector<int> &v, int starting_idx, int last_idx){
    if(starting_idx >= last_idx)  return;
    int pivot = partition(v, starting_idx, last_idx);
    quickSort(v, starting_idx, pivot - 1);
    quickSort(v, pivot + 1, last_idx);
}

int main(){
    int arr[] = {1, 2, 4, 5, 32, 1 ,4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> v(arr, arr + n);
    cout<<"Original Array is: ";
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }

    quickSort(v, 0, v.size() - 1);

    cout<<"\nSorted Array is: ";
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }

    return 0;
}
