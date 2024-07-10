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

vector<int> inorderTraversal(node * root){
    vector<int> inorder;
    node * temp = root;
    stack<node*> st;
    while(true){
        if(temp!=NULL){
            st.push(temp);
            temp = temp->left;
        }
        else{
            if(st.empty()==true) break;
            temp = st.top();
            st.pop();
            inorder.push_back(temp->data);
            temp = temp->right;
        }


    }

    return inorder;
}

int main() {
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(5);  

    vector<int> result = inorderTraversal(root); 

    // Printing the result
    for(auto i : result) {
            cout << i << " ";
    } 

    return 0;
}
