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

vector<int> BottomView(node *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, int> mpp;
    queue<pair<node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        node *temp = it.first;
        int line = it.second;
        mpp[line] = temp->data;
        if (temp->left != NULL)
        {
            q.push({temp->left, line - 1});
        }
        if (temp->right != NULL)
        {
            q.push({temp->right, line + 1});
        }
    }

    for (auto it : mpp)
    {
        ans.push_back(it.second);
    }

    return ans;
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(5);
    root->left->left = new node(7);

    vector<int> result = BottomView(root);

    // Printing the result
    for (auto level : result)
    {
        cout << level << " ";
    }

    return 0;
}
