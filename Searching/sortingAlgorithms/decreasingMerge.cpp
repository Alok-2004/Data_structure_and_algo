
#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int> a, vector<int> b, vector<int> &v){
    int n1 = 0, n2 = 0, k = 0;
    while(n1 < a.size() && n2 < b.size()){
        if(a[n1] >= b[n2]){
            v[k] = a[n1];
            k++;
            n1++;
        }else{
            v[k] = b[n2];
            k++;
            n2++;
        }
    }
        // Insert remaining elements from a
    while (n1 < a.size())
    {
        v[k++] = a[n1++];
    }

    // Insert remaining elements from b
    while (n2 < b.size())
    {
        v[k++] = b[n2++];
    }
       
}

void mergeSort( vector<int> &v ){
    int n = v.size();

    if(n == 1)  return;
    int n1 = n/2;
    int n2 = n - n/2;
    vector<int> a(n1), b(n2);
    for(int i = 0; i<n1; i++){
        a[i] = v[i];
    }

    for(int i = 0; i<n2; i++){
        b[i] = v[i + n1];
    }

    mergeSort(a);
    mergeSort(b);

    merge(a, b, v);

}

int main(){
    int arr[] = {2, 4, 3, 1, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int>a(arr, arr+n);
    for(int i = 0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    mergeSort(a);

    for(int i = 0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }
}


