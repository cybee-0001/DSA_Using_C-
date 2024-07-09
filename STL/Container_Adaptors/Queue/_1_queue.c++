#include<iostream>
#include<queue>
using namespace std;

int main(){

    queue<string> q;
    q.push("abc");
    q.push("def");
    q.push("ghi");

    cout<<"Top Element : "<<q.front()<<endl;

    q.pop();
    cout<<"Top Element : "<<q.front()<<endl;

    cout<<"Size of stack : "<<q.size()<<endl;

    cout<<"Is empty or not : "<<q.empty()<<endl;

    return 0;
}
