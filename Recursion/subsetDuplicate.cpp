#include<iostream>
#include<vector>
#include<string>
using namespace std;

void storeSubset(string ans, string orig, vector<string> &v, bool flag){
	if(orig == ""){
		v.push_back(ans);
		return;
	}	
	
	char ch = orig[0];
	if(orig.size() == 1){
		if(flag == true) storeSubset(ans + ch, orig.substr(1), v, true);
		storeSubset(ans, orig.substr(1), v, true);
		return;
	}
	
	char dh = orig[1];
	if(ch == dh){ // duplicate
		if(flag == true) storeSubset(ans + ch, orig.substr(1), v, true);
		storeSubset(ans, orig.substr(1), v, false);
	}else{// No duplicate
		if(flag == true) storeSubset(ans + ch, orig.substr(1), v, true);
		storeSubset(ans, orig.substr(1), v, true);
	}
}

int main(){
	string str = "akvkjndfisiufvbfuidbniugvwhjkbaa";
	vector<string> v;
	bool flag = true;
	storeSubset("", str, v, true);
	for(int i = 0; i<v.size(); i++){
		cout<<v[i]<<" ";
	}
}
