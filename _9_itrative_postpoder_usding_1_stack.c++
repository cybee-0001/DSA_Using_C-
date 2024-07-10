#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
    node(int val) {
        data = val;
        left = right = NULL;
    }
};

vector<int> postorderTtaversal(node * root){
    vector<int> postorder;

    if(root ==NULL) return postorder;
    stack<node *> st1;
    node * car = root; 
    st1.push(root);
    while(car!=NULL || !st1.empty()){
        if(car!=NULL){
            st1.push(car);
            car=car->left;
        }
        else{
            node * temp = st1.top()->right;
            if(temp==NULL){
                temp = st1.top();
                st1.pop();
                postorder.push_back(temp->data);
                while(!st1.empty() && temp==st1.top()->right){
                    temp = st1.top();
                    st1.pop();
                    postorder.push_back(temp->data);
                }
            }
            else{
                car=temp;
            }
        }
    }

    return postorder;
}

int main() {
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(5);  

    vector<int> result = postorderTtaversal(root); 

    // Printing the result
    for(auto i : result) {
            cout << i << " ";
    } 

    return 0;
}
