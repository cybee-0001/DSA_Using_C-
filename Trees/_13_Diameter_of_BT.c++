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



int height(node *root, int &diameter)
{
    if (!root)
    {
        return 0;
    }

    int lh = height(root->left,diameter);
    int rh = height(root->right,diameter);
    diameter = max(diameter,lh+rh);
    return 1 + max(lh, rh);
}

int diameterOfBinaryTree(node * root){
    int diameter=0;
    height(root,diameter);
    return diameter;
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(5);

    int result = diameterOfBinaryTree(root);

    // Printing the result
    cout << "The diameter of the binary tree will be : " << result << endl;

    return 0;
}
