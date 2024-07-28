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

int maxWidthOfBT(node* root){
    if(!root){
        return 0;
    }
    int ans=0;
    
    queue<pair<node *, int>> q;
    q.push({root,0});

    while(!q.empty()){
        int size = q.size();
        int mmin = q.front().second;
        int first, last;
        for(int i = 0; i < size; i++){
            int cur_id = q.front().second-mmin;
            node* temp = q.front().first;
            q.pop();
            if(i==0){
                first=cur_id;
            }
            if(i==size-1){
                last=cur_id;
            }
            if(temp->left){
                q.push({temp->left, cur_id*2+1});
            }
            if(temp->right){
                q.push({temp->right, cur_id*2+2});
                }
        }
        ans = max(ans, last-first+1);
    }
    return ans;
}

int main() {
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(2);
    root->left->right = new node(5);
    root->left->left = new node(7);
    root->right->right = new node(7);
    root->right->left = new node(5);  

    int result = maxWidthOfBT(root); 

    // Printing the result
    cout <<"The maximun vidth of the binary tree will be : "<< result << " ";
    cout << endl;

    return 0;
}
