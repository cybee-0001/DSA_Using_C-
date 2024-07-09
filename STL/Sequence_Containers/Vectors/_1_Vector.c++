#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> v;
    cout<<"Size --> "<<v.size()<<endl;
    cout<<"capacity --> "<<v.capacity()<<endl;

    v.push_back(1);
    cout<<"Size --> "<<v.size()<<endl;
    cout<<"capacity --> "<<v.capacity()<<endl;

    v.push_back(2);
    cout<<"Size --> "<<v.size()<<endl;
    cout<<"capacity --> "<<v.capacity()<<endl;

    v.push_back(5);
    cout<<"Size --> "<<v.size()<<endl;
    cout<<"capacity --> "<<v.capacity()<<endl;

    cout<<"Element at second Index : "<<v.at(2)<<endl;
    cout<<"First Element : "<<v.front()<<endl;
    cout<<"Last Element : "<<v.back()<<endl;

    cout<<"Before pop :"<<endl;
    for(int i:v){
        cout<<i<<" ";
    }cout<<endl;

    v.pop_back();

    cout<<"After pop : "<<endl;
    for(int i:v){
        cout<<i<<" ";
    }cout<<endl;

    cout<<"Before clear : "<<endl;
    cout<<"Size --> "<<v.size()<<endl;
    cout<<"capacity --> "<<v.capacity()<<endl;

    v.clear();

    cout<<"After clear : "<<endl;
    cout<<"Size --> "<<v.size()<<endl;
    cout<<"capacity --> "<<v.capacity()<<endl;

    vector<int> a(5,1);
    for(int i:a){
        cout<<i<<" ";
    }cout<<endl;

    vector<int> last(a);
    for(int i:last){
        cout<<i<<" ";
    }cout<<endl;

    return 0;
}