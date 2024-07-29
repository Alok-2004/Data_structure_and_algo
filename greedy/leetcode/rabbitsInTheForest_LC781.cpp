/*
781. Rabbits in Forest
There is a forest with an unknown number of rabbits. 
We asked n rabbits "How many rabbits have the same color as you?" 
and collected the answers in an integer array answers where 
answers[i] is the answer of the ith rabbit.
Given the array answers, return the minimum number of rabbits that could be in the forest.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& a) {
        unordered_map<int , int> uM;
        int res = 0;
        for(int i = 0 ; i < a.size() ; i++){
            if(uM[a[i] + 1] == a[i] + 1){
                res += uM[ a[i] + 1]; 
                uM[a[i] + 1] = 0;
            }
            uM[a[i]+1]++;
        }
        for(auto x : uM){
            res += x.first;
        }
        return res;
    }
};

int main(){
	
}
