#include <iostream>
#include <map>
using namespace std;

int main(){

    map<int,string> m;
    m[1]="one";
    m[2]="two";
    m[3]="three";
    m[4]="four";
    m[5]="five";

    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<<"After Insertion : "<<endl;
    m.insert({6,"six"});

    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<<"Finding element : "<<m.count(6)<<endl;

    cout<<"After Eraseing : "<<endl;
    m.erase(6);
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }

    cout<<"aaa"<<endl;
    auto it = m.find(3);
    for(auto i=it; i!=m.end();i++){
        cout<<(*i).first<<" "<<(*i).second<<endl;
    }

    return 0;
}