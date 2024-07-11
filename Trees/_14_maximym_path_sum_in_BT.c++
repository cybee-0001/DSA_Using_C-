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



int maxPathDown(node *root, int &maxi)
{
    node * temp = root;
    if (temp == NULL)
    {
        return 0;
    }

    int left = max(0, maxPathDown(temp->left, maxi));
    int right = max(0, maxPathDown(temp->right,maxi));
    maxi = max(maxi,left+right+temp->data);
    return max(left,right)+temp->data;
}

int maxPathSum(node * root){
    int maxi= INT_MIN;
    maxPathDown(root,maxi);
    return maxi;
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(5);

    int result = maxPathSum(root);

    // Printing the result
    cout << "The maximum path of the binary tree will be : " << result << endl;

    return 0;
}
