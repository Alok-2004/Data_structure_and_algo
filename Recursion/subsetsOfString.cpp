#include<iostream>
#include<string>
#include<vector>

using namespace std;

void subset(string ans, string original, vector<string> &v){
	if(original == ""){
		cout<<ans<<endl;
		v.push_back(ans);
		return;
	}
	char ch  = original[0];
	subset(ans, original.substr(1), v)	;
	subset(ans + ch, original.substr(1), v);
}

int main(){
	string str = "aaad";
	vector<string> v;
	subset("", str, v);
	return 0;
}


