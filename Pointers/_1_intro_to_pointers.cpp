#include <bits/stdc++.h>
using namespace std;

int main(){
    //Simple pointers 
    int i1=1;
    int *ptr1=&i1;
    // cout<<*ptr1<<endl;
    // cout<<ptr1<<endl;

    //problem 2
    int i2=2;
    int *ptr2=&i2;
    int k1=(*ptr2);
    k1=k1+1;
    // cout<<k1<<endl;
    // cout<<i2<<endl;

    //problem 3
    int i3=3;
    int *ptr3=&i3;
    *ptr3=*ptr3+1;
    cout<<*ptr3<<endl;
    cout<<i3<<endl;

    return 0;
}