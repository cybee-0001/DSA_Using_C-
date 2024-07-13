#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

bool isSymmetricHelp(node * left, node * right){
    if(left == NULL && right == NULL){
        return left==right;
    }
    if(left->data!=right->data){
        return false;
    }

    return isSymmetricHelp(left->left,right->right)&&isSymmetricHelp(left->right,right->left);
}

bool isSymmetric(node * root){
    return root == NULL || isSymmetricHelp(root->left, root->right);
}  

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(2);
    root->left->right = new node(5);
    root->left->left = new node(7);
    root->right->right = new node(7);
    root->right->left = new node(5);

    bool result = isSymmetric(root);

    // Printing the result
    if(result){
        cout << "The tree is symmetric." << endl;
    }
    else{
        cout << "The tree is not symmetric." << endl;
    }

    return 0;
}
