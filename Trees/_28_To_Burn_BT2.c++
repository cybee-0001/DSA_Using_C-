#include <iostream>
#include <queue>
#include <map>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    int minTime(Node *root, int start) {
        map<Node *, Node *> parentMap;
        Node *target = bfsToMapParents(root, parentMap, start);
        int maxTime = findMaxDistance(parentMap, target);
        return maxTime;
    }

private:
    Node* bfsToMapParents(Node *root, map<Node *, Node *> &parentMap, int start) {
        queue<Node *> q;
        q.push(root);
        Node *res = nullptr;
        
        while (!q.empty()) {
            Node *temp = q.front();
            q.pop();
            
            if (temp->data == start) {
                res = temp;
            }
            
            if (temp->left) {
                parentMap[temp->left] = temp;
                q.push(temp->left);
            }
            if (temp->right) {
                parentMap[temp->right] = temp;
                q.push(temp->right);
            }
        }
        
        return res;
    }

    int findMaxDistance(map<Node *, Node *> &parentMap, Node *target) {
        queue<Node *> q;
        q.push(target);
        map<Node *, bool> visited;
        visited[target] = true;
        int maxTime = 0;
        
        while (!q.empty()) {
            int sz = q.size();
            bool flag = false;
            
            for (int i = 0; i < sz; ++i) {
                Node *current = q.front();
                q.pop();
                
                if (current->left && !visited[current->left]) {
                    visited[current->left] = true;
                    q.push(current->left);
                    flag = true;
                }
                if (current->right && !visited[current->right]) {
                    visited[current->right] = true;
                    q.push(current->right);
                    flag = true;
                }
                if (parentMap[current] && !visited[parentMap[current]]) {
                    visited[parentMap[current]] = true;
                    q.push(parentMap[current]);
                    flag = true;
                }
            }
            if (flag) {
                maxTime++;
            }
        }
        
        return maxTime;
    }
};

// Helper function to create a new Node
Node* createNode(int data) {
    return new Node(data);
}

int main() {
    Solution sol;

    // Create the tree
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = nullptr;

    // Find the time to burn the tree starting from node with value 2
    int start = 2;
    int result = sol.minTime(root, start);

    // Output the result
    cout << "The maximum time to burn the BT will be: " << result << endl;

    return 0;
}
