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

int findMaxDistance(map<node *, node *> &mpp, node *target)
{
    queue<node *> q;
    q.push(target);
    map<node *, int> vis;
    vis[target] = 0;
    int maxi = 0;
    while (!q.empty())
    {
        int sz = q.size();
        int fl = 0;
        for (int i = 0; i < sz; i++)
        {
            auto temp = q.front();
            q.pop();
            if (temp->left && !vis[temp->left])
            {
                fl = 1;
                vis[temp->left] = 1;
                q.push(temp->left);
            }
            if (temp->right && !vis[temp->right])
            {
                fl = 1;
                vis[temp->right] = 1;
                q.push(temp->right);
            }
            if (mpp[temp] && !vis[mpp[temp]])
            {
                fl = 1;
                vis[mpp[temp]] = 1;
                q.push(mpp[temp]);
            }
        }
        if (fl)
        {
            maxi++;
        }
    }

    return maxi;
}

node *bfsToMapParents(node *root, map<node *, node *> &mpp, int start)
{
    queue<node *> q;
    q.push(root);
    node *res;
    while (!q.empty())
    {

        node *temp = q.front();

        if (temp->data == start)
        {
            res = temp;
        }

        q.pop();

        if (temp->left)
        {
            mpp[temp->left] = temp;
            q.push(temp->left);
        }
        if (temp->right)
        {
            mpp[temp->right] = temp;
            q.push(temp->right);
        }
    }

    return res;
}

int timeToBurn(node *root, int start)
{
    map<node *, node *> mpp;
    node *target = bfsToMapParents(root, mpp, start);
    int maxi = findMaxDistance(mpp, target);
    return maxi;
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(4);
    root->left->left = new node(5);
    root->right->right = new node(6);
    root->right->left = new node(7);

    int result = timeToBurn(root,2);

    // Printing the result
    cout << "The maximun time to burn the BT will be : " << result << " ";
    cout << endl;

    return 0;
}
