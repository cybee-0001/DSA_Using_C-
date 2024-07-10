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

int BalancedBinaryTree(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = BalancedBinaryTree(root->left);

    if(lh==-1){
        return -1;
    }
    int rh = BalancedBinaryTree(root->right);

    if(rh==-1){
        return -1;
    }
    if(abs(lh-rh)>1){
        return -1;
    }

    return 1 + max(lh, rh);
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(5);

    int result = BalancedBinaryTree(root);

    if(result==-1){
        cout<<"Not Balanced"<<endl;
    }
    else{
        cout<<"Balanced"<<endl;
    }

    return 0;
}
