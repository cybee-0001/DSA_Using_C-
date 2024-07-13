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

void recursion(node * root, int level, vector<int> &ans){
    if(root == NULL) return;
    if(ans.size()==level){
        ans.push_back(root->data);
    }
    recursion(root->left, level+1, ans);
    recursion(root->right, level+1, ans);
    
}

vector<int> LeftSideView(node * root){
    vector<int> ans;
    recursion(root,0,ans);
    return ans;
}

int main() {
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(5);
    root->left->left = new node(7);   

    vector<int> result = LeftSideView(root); 

    // Printing the result
    for (auto level : result) {
            cout << level << " ";
    } 

    return 0;
}
