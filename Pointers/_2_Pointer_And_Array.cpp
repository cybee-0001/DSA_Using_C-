#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    // cout<<arr<<endl;
    // cout<<&arr[0]<<endl;
    // cout<<*arr<<endl;

    // arr[i]=*(arr+i)

    // cout<<*(arr+1)<<endl;
    // cout<<*(arr+2)<<endl;

    // cout<<3[arr]<<endl;
    int *p = &arr[0];

    cout << sizeof(arr) << endl;
    cout << sizeof(p) << endl;

    return 0;
}