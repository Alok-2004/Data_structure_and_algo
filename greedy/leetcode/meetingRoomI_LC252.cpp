/*
251 : Meeting room 1
Given an array of meeting time intervals consisting of start 
and end times [[s1,e1],[s2,e2],...] (si < ei)
find if a single person can attend all the meeting.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canAttendMeetings(vector<Interval> &intervals) {
    	vector<int>st;
    	vector<int>et;
    	for(int i = 0; i < intervals.size() ; i++){
    		st.push_back(intervals[i][0]);
    		et.push_back(intervals[i][1]);
		}
		
		sort(st.begin() , st.end());
		sort(et.begin() , et.end());
		
		int res = 0;
		int curr = 0;
		int i = 0, j = 0;
		
		while( i < st.size() and j < et.size()){
			if( et[j] > st[i] ){
				curr++;
				i++;
			}
			else if( et[j] < st[i] ){
				curr--;
				j++;
			}
			else{
				j++;
				i++;
			}
			res = max(res , curr);
		}
		if(res > 1) return false;
		else true;;
    }
};

int main(){
	
}
