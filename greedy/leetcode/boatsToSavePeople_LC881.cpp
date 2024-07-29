/*
881. Boats to Save People
You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0;
        int j = people.size() - 1;
        int res = 0;
        while( i <= j){
            if( people[i] + people[j] > limit){
                j--;
            }else if( people[i] + people[j] <= limit ){
                j--;
                i++;
            }
            res++;
        }
        return res;
    }
};

int main(){

}