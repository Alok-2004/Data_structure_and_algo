#include<iostream>
#include<queue> // stl for priority queue
using namespace std;

int main(){
    priority_queue<int>pq; // By default its max heap
    pq.push(10);
    pq.push(34);
    pq.push(244);
    pq.push(10);
    pq.push(14);

    cout<<pq.top()<<endl;  //244
    pq.pop(); // 244 is removed
    cout<<pq.top()<<endl; //34


    priority_queue<int, vector<int>, greater<int> >  minHeap;
    minHeap.push(10);
    minHeap.push(34);
    minHeap.push(244);
    minHeap.push(10);
    minHeap.push(14);

    cout<<minHeap.top();    
}