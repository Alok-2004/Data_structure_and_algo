#include<iostream>
using namespace std;

int pwr(int b, int e){
    if(e == 0) return 1;

    return b*pwr(b, e-1);
}

int main(){
    int b ;
    cin>>b;

    int e;
    cin>>e;

    cout<<pwr(b,e);
}