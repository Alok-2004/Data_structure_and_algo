#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

int main(){
  unordered_map<string, int> s;
  pair<string, int>p1;
  p1.first = "Alok";
  p1.second = 34;

  s.insert(p1);
  // s.insert("alok1", 23);// wrong way
  s.insert(make_pair("alok1", 23));
  // or using intializer list
  s.insert({"alok2", 21});
// or
  s["hello"] = 34; // best way
  
  
  // printing
  for(auto ele:s){
    cout<<ele.first<<" "<<ele.second<<endl;
  }

  // or

  for(pair<string, int>m : s){
    cout<<m.first<<" "<<m.second<<endl;
  } 

  // erase
  s.erase("Alok");

}