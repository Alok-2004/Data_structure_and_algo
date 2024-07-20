/*
295. Find Median from Data Stream
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
*/

/*
Median is the middle value
    if(size of array is even){
        average of two middle values
    }
*/

#include<bits/stdc++.h>
using namespace std;

// Time limit exceeded
/*
class MedianFinder {
public:
    vector<int> v;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        v.push_back(num);
        sort(v.begin(), v.end());
    }
    
    double findMedian() {
        int s = v.size();
        double res;
        if(v.size() % 2 != 0 ){
            int temp = v[ s / 2];
            res = static_cast<double>(temp);
        }else{
            int temp = v[s / 2] + v[ (s / 2) - 1];
            res = static_cast<double>(temp) / 2;
        }
        return res;
    }
};
*/


// using minHeap and maxHeap

auto init = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();


class MedianFinder {
public:
    priority_queue<int>left;
    priority_queue<int, vector<int>, greater<int>>right;
    MedianFinder(){}

   // time complexity O(logn)

    void addNum(int num) {
        if(left.size() != 0){
            if(num <= left.top()){
                left.push(num);
            }else{
                right.push(num);
            }
        }else left.push(num);

        if(left.size() > (right.size() + 1)){
            int x = left.top();
            left.pop();
            right.push(x);
        }else if( (left.size() + 1) < right.size() ){
            int x = right.top();
            right.pop();
            left.push(x);
        }
    }
    
    double findMedian() {
        if(left.size() != right.size()){
            if(left.size() > right.size())  return left.top() / 1.0;
            else return right.top() / 1.0;
            
        }else{
            return ( left.top() + right.top() ) / 2.0;
        }        
    }
};