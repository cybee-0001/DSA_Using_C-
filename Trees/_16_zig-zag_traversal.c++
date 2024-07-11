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

vector<vector<int>> zigzagLevelOrder(node* root){
    vector<vector<int>> result;
    if(root == NULL) return result;

    queue<node*> q;
    q.push(root);
    bool leftToRight = true;
    while(!q.empty()){
        int size = q.size();
        vector<int> level(size);
        for(int i = 0; i < size; i++){
            node* temp = q.front();
            q.pop();
            //find position to fill node's value
            int index = (leftToRight)? i : size - i - 1;
            level[index] = temp->data;
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
        //After this level
        leftToRight = !leftToRight;
        result.push_back(level);
    }
    return result;
}

int main() {
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(5);
    root->left->left = new node(7);   

    vector<vector<int>> result = zigzagLevelOrder(root); 

    // Printing the result
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    } 

    return 0;
}
