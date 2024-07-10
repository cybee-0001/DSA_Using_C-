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

int maxDepth(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    queue<node *> q;
    q.push(root);
    int level=0;
    while (!q.empty())
    {
        int size = q.size(); 
        for (int i = 0; i < size; i++)
        {
            node *temp = q.front();
            q.pop();
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
            
        }
        level=level+1;
    }
    return level;
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(5);

    int result = maxDepth(root);

    // Printing the result
    cout << "The height of the binary tree will be : " << result << endl;

    return 0;
}
