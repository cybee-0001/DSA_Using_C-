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

node *buildTree2(vector<int> &inorder, int is, int ie, vector<int> &postorder, int ps, int pe, map<int, int> hm)
{
    if (ps > pe || is > ie)
    {
        return NULL;
    }
    node *root = new node(postorder[pe]);
    int inRoot = hm[root->data];
    int numsLeft = inRoot - is;

    root->left = buildTree2(inorder, is, inRoot - 1, postorder, ps, ps + numsLeft - 1, hm);
    root->right = buildTree2(inorder, inRoot + 1, ie, postorder, ps + numsLeft, pe - 1, hm);
    return root;
}

node *buildTree(vector<int> &postorder, vector<int> &inorder)
{

    if (postorder.size() != inorder.size())
    {
        return NULL;
    }
    map<int, int> hm;

    for (int i = 0; i < inorder.size(); i++)
    {
        hm[inorder[i]] = i;
    }

    node *root = buildTree2(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, hm);
    return root;
}

// Function to perform in-order traversal
void inorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main()
{
    vector<int> postorder = {40, 50, 20, 60, 30, 10};
    vector<int> inorder = {40, 20, 50, 10, 60, 30};
    node *root = buildTree(postorder, inorder);

    // Print the tree using in-order traversal
    cout << "In-order Traversal: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
