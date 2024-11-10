#include<bits/stdc++.h>
using namespace std;

void function1(int &a){
    cout<<&a<<endl;
}

void function2(int *p){
    *p=*p+1;
}

int main(){

    int a=5;
    int *p = &a;
    cout<<&a<<endl;

    function1(a);
    function2(p);
    cout<<a<<endl;
    return 0;
}