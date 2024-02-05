#include<iostream>
using namespace std;

void fun(int n){
    if(n == 0)  return;
    cout<<"\nGood morning";
    n = n - 1;
    fun(n);
}

int main(){
    int n;
    cin>>n;

    fun(n);
}