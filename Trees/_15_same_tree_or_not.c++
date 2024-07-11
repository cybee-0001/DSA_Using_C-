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

bool isSame(node *p, node *q) {
    if (p == NULL || q == NULL) {
        return (p == q);
    }

    return (p->data == q->data) && isSame(p->left, q->left) && isSame(p->right, q->right);
}

int main() {
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(5);

    struct node *root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);
    root1->left->right = new node(5);

    bool result = isSame(root, root1);

    // Printing the result
    if(result) {
        cout << "The trees are same" << endl;
    } else {
        cout << "The trees are not same" << endl;
    }

    return 0;
}
