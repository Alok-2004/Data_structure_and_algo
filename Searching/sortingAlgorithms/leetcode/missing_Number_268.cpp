#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int> nums = {4, 1, 8, 2, 6, 3, 7};
    //Method one
    /*
    vector<int> check(nums.size() + 1, false);

    for(int i = 0; i < nums.size(); i++){
        check[nums[i]] = true;
    }

    for(int i = 0; i<check.size(); i++){
        
        if(check[i] == false){
            cout<<i<<" ";
        }
    }

    */
    //Method 2
    /*
    int n = nums.size();
    int actual_sum = (n*(n + 2)) / 2;  // from 0 to n
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += nums[i];
    }
    cout<< "Sum " << sum << " Actual Sum "<< actual_sum<<endl;
    cout<<  sum - actual_sum;
    */

   // Method 3
   /*
    int missingNumber(vector<int>& nums) {
        int n =  nums.size();
        int i = 0;
        while( i < n ){
            int correctIdx = nums[i];
            if(correctIdx == i  || nums[i] == n)  i++;
            else  swap(nums[i], nums[correctIdx]);
        }

        for(int j = 0; j<n; j++){
            if(nums[j] != j)  return j;
        }

        return n;
    */
   
    return 0;
}