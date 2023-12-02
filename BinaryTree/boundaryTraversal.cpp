#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    long long  data;
    Node *left, *right;

    Node(long long val=0): data(val), left(NULL), right(NULL) {}
};

void leftBoundary(Node* root, vector<int>& ans){
        if(root == NULL || (root -> left == NULL && root -> right == NULL)){
            return;
        }
        
        ans.push_back(root -> data);
        
        if(root -> left != NULL){
            leftBoundary(root -> left, ans);
        }
    
        else{
            leftBoundary(root -> right, ans);
        }
    }

    void rightBoundary(Node* root, vector<int>& ans){
        if(root == NULL || (root -> left == NULL && root -> right == NULL)){
            return;
        }
        
        if(root -> right != NULL){
            rightBoundary(root -> right, ans);
        }
    
        else{
            rightBoundary(root -> left, ans);
        }
        
        ans.push_back(root -> data);
    }

    void leafNodes(Node* root, vector<int>& ans){
        if(root == NULL){
            return;
        }
        
        if(root -> left == NULL && root -> right == NULL){
            ans.push_back(root -> data);
            return;
        }
        
        leafNodes(root -> left, ans);
        leafNodes(root -> right, ans);
    }
    
    
    vector <int> boundary(Node *root)
    {
        //Your code here
          vector<int> ans;

          if(root == NULL){
              return ans;
          }
             
          ans.push_back(root -> data);
            
          // Traverse left boundary.
          leftBoundary(root -> left, ans);
            
          // Traverse for leaf nodes.
          leafNodes(root -> left, ans);
          leafNodes(root -> right, ans);
            
          // Traverse right boundary.
          rightBoundary(root -> right, ans);
            
          return ans;
    }
Node *newNode(int val){
    Node *root = (Node *)malloc(sizeof(Node));
    *root = Node(val);
    return root; 
}
int main()
{
    // Let us construct the tree given in the above diagram
    Node* root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->left->right->left = newNode(5);
    root->left->right->left->left = newNode(6);
    root->left->right->left->left->right = newNode(7);


 
    vector<int> ans = boundary(root);
    for(int i:ans) cout<<i<<" ";
    cout<<endl;
 
    return 0;
}

