#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *left, *right;
    Node(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
};

Node *pred(Node *root){
    while(1){
        if(root->right) root=root->right;
        else return root;
    }
}

Node* flat(Node *root){
    if(!root) return NULL;
    
    if(!root->left){
        root->right=flat(root->right);
        return root;
    }

    
    
    Node *temp=NULL, *right=NULL;
    
    right = flat(root->right);
    temp = pred(root->left);
    Node *left=flat(root->left);
    
    temp->right = root;
    root->right = right;
    root->left=NULL;
    return left;
    
    
}

void flatten(Node* &root) {
    root = flat(root);
    return;

}

void preorder(Node *root){
    if(root == NULL) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}

int main()
{
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);
 
    // Calling required function
    flatten(root);
    preorder(root);
    cout<<endl;

 
    return 0;
}