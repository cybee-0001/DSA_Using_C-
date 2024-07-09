#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    cout<<"Finding Element : "<<binary_search(v.begin(),v.end(),5)<<endl;
    cout<<"Finding Element : "<<binary_search(v.begin(),v.end(),6)<<endl;

    cout<<"Lower Bound : "<<lower_bound(v.begin(),v.end(),6)-v.begin()<<endl;
    cout<<"Upper Bound : "<<upper_bound(v.begin(),v.end(),4)-v.begin()<<endl;

    int a = 3;
    int b = 5;
    cout<<"max -->"<<max(a,b)<<endl;
    cout<<"min -->"<<min(a,b)<<endl;

    swap(a,b);
    cout<<"a = "<<a<<" b = "<<b<<endl;

    string abcde = "abcde";
    reverse(abcde.begin(),abcde.end());
    cout<<abcde<<endl;

    rotate(v.begin(),v.begin()+1,v.end());
    cout<<"After Rotate"<<endl;
    for(int i : v){
        cout<<i<<" ";
    }


    return 0;
}