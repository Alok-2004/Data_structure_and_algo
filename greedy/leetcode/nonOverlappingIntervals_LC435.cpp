/*
435. Non-overlapping Intervals
Given an array of intervals intervals where intervals[i] = [starti, endi], 
return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping
*/


// This will wrong answer because here we are taking into account the range as
// between 1,2 and 1,4  first have more chances of fullfilling the question requirement of minimum removals

/*
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& itrl) {
        int n = itrl.size();
		if(n == 0){
			return {};
		}
		sort(itrl.begin() , itrl.end());
        int res = 0;
        int j = 0;
		for(int i = 1; i < n ; i++){
			if( itrl[j][1] > itrl[i][0] ){
                res++;
			}else{
                j = i; // lowest hanging fruit 
            }
		}
        return res;
    }
};
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& itrl) {
        int n = itrl.size();
		if(n == 0){
			return {};
		}
		sort(itrl.begin() , itrl.end());
        int res = 0;
        int lastEndTime = itrl[0][1];
		for(int i = 1; i < n ; i++){
			if( lastEndTime > itrl[i][0] ){
                res++;
                lastEndTime = min(lastEndTime , itrl[i][1]); 
			}else{
                lastEndTime = itrl[i][1];
            }
		}
        return res;
    }
};

