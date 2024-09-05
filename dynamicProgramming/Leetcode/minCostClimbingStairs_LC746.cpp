#include<bits/stdc++.h>
using namespace std;

// Recursive solution
/*
class Solution {
public:
    int helper(vector<int> &cost , int i , int sum){
        if( i >= cost.size() ) return sum;
        return min( helper(cost , i+1 , sum + cost[i]) , helper(cost , i+2 , sum + cost[i]) );    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        return min( helper(cost , 0 , 0) , helper(cost , 1, 0) );
    }
};
*/


//Tabulation
/*
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        for(int i = 2; i < n; i++){
            cost[i] += min(cost[i-1] , cost[i-2]);
        }
        return min(cost[n-1] , cost[n-2]);
    }
};
*/
int main(){

}
