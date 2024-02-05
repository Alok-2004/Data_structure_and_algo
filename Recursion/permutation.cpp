//Permutation
// Bad interms of TC and SC
#include<iostream>
#include<string>
using namespace std;

void permutation(string ans, string orig){
	
	if(orig == ""){
		cout<<ans<<endl;
		return;
	}
	for(int i = 0; i <= orig.size() - 1; i++){
		char ch = orig[i];
		string left = orig.substr(0,i);
		string right = orig.substr(i+1);
		permutation(ans+ch, left + right);
	}
	// orign.substr(starting point, number of character)
}

int main(){
	string str = "abcd";
	permutation("", str);
}
