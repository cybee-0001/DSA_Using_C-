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

node* buildTree2(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> inMap) {
    if (preStart > preEnd || inStart > inEnd) {
        return NULL;
    }
    node *root = new node(preorder[preStart]);
    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = buildTree2(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
    root->right = buildTree2(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);
    return root;
}

node* buildTree(vector<int> &preorder, vector<int> &inorder) {
    map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }

    node *root = buildTree2(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
    return root;
}

// Function to perform in-order traversal
void inorderTraversal(node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    node *root = buildTree(preorder, inorder);

    // Print the tree using in-order traversal
    cout << "In-order Traversal: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
