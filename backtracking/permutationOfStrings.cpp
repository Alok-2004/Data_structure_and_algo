// Permutation of strings

#include<bits/stdc++.h>
using namespace std;

vector<string>res;

void permutation(string original , string resultant){
	if(original.size() == 0){
		res.push_back(resultant);
		return;
	}
	
	for(int i = 0 ; i < original.size() ; i++){
	    string left = "";
		string right = "";
		left = original.substr(0 , i);
		right = original.substr(i+1);
		
		permutation(left + right , resultant + original[i]);
	}
	
	return;
}

int main() {
    string original = "abc";
    permutation(original, "");
    for (string perm : res) {
        cout << perm << endl;
    }
    return 0;
}
