#include <iostream>
using namespace std;

class MinHeap {
public:
    int arr[50];
    int idx;

    MinHeap() {
        idx = 1;
    }

    int top() {
        return arr[1];
    }

    void push(int x) {
        arr[idx] = x;
        int i = idx;
        idx++;
        while (i != 1) {
            int parent = i / 2;
            if (arr[i] < arr[parent]) {
                swap(arr[i], arr[parent]);
                i = parent;
            } else break;
        }
    }

    int size() {
        return idx - 1;
    }

    void pop() {
        idx--;
        arr[1] = arr[idx];
        //Rearrangement

        int i = 1;
        while (true)
        {
            int left = 2 * i, right = 2 * i + 1;
            
            if(left > idx - 1) break;
            
            if(right >idx - 1){
                if(arr[i] > arr[left]){
                    swap(arr[i], arr[left]);
                    i = left;
                }
                break;
            }
            if(arr[left] > arr[right]){
                if(arr[i] > arr[left]){
                    swap(arr[i], arr[left]);
                    i = left;
                }
                else break;
            }
            
            else{
                if(arr[i] > arr[right]){
                    swap(arr[i], arr[left]);
                    i = right;
                }else break;
            }
        }
        
    }

    void display(){
        for(int i = 0; i<idx; i++){
            cout<<arr[idx]<<" ";
        }
    }
};

int main() {
    MinHeap pq;
    pq.push(10);
    pq.push(2);
    pq.push(30);
    pq.push(2130);
    pq.push(0);
    cout << "Top element: " << pq.top() << endl;

    pq.pop();
    cout << "Top element after pop: " << pq.top() << endl;

    return 0;
}
