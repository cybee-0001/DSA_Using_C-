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

bool isLeaf(node * root){
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    return false;
}
void addLeftBoundary(node * root, vector<int> &res){
    node *cur = root->left;
    while(cur){
        if(!isLeaf(cur)){
            res.push_back(cur->data);
        }
        if(cur->left){
            cur = cur->left;
        }
        else{
            cur = cur ->right;
        }
    }
}

void addLeaves(node * root, vector<int> &res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }

    if(root->left){
        addLeaves(root->left, res);
    }
    if(root->right){
        addLeaves(root->right, res);
    }
}

void addRightBoundary(node * root, vector<int> &res){
    node *cur = root->right;
    vector<int> tmp;
    while(cur){
        if(!isLeaf(cur)){
            tmp.push_back(cur->data);
        }
        if(cur->right){
            cur = cur->right;
        }
        else{
            cur = cur ->left;
        }
    }

    for(int i = tmp.size()-1; i>=0; --i){
        res.push_back(tmp[i]);
    }
}


vector<int> printBoundary(node* root){
    vector<int> res;
    if(!root) return res;
    if(!isLeaf(root)){
        res.push_back(root->data);
    }
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);
    return res;
}

int main() {
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(5);
    root->left->left = new node(7);   

    vector<int> result = printBoundary(root); 

    // Printing the result
    for (auto level : result) {
            cout << level << " ";
    } 

    return 0;
}
