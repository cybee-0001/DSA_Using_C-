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

vector<int> PreorderTraversal(node * root){
    vector<int> preorder;

    if(root==NULL){
        return preorder;
    }

    stack<node *> st;
    st.push(root);
    while(!st.empty()){
        root=st.top();
        st.pop();
        preorder.push_back(root->data);
        if(root->right!=NULL){
            st.push(root->right);
        }
        if(root->left!=NULL){
            st.push(root->left);
        }
    }

    return preorder;
}

int main() {
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(5);  

    vector<int> result = PreorderTraversal(root); 

    // Printing the result
    for(auto i : result) {
            cout << i << " ";
    } 

    return 0;
}
