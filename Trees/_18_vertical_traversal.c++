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

vector<vector<int>> verticalTraversal(node *root)
{
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<node *, pair<int, int>>> todo;
    todo.push({root, {0, 0}});
    while (!todo.empty())
    {
        auto p = todo.front();
        todo.pop();
        node *cur = p.first;
        int x = p.second.first, y = p.second.second;
        nodes[x][y].insert(cur->data);
        if (cur->left)
        {
            todo.push({cur->left, {x - 1, y + 1}});
        }
        if (cur->right)
        {
            todo.push({cur->right, {x + 1, y + 1}});
        }
    }
    vector<vector<int>> ans;
    for (auto p : nodes)
    {
        vector<int> temp;
        for (auto q : p.second)
        {
            temp.insert(temp.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(temp);
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

    vector<vector<int>> result = verticalTraversal(root);

    // Printing the result
    for (const auto &level : result)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
