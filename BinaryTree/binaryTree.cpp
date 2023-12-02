#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    long long  data;
    Node *left, *right;

    Node(long long val=0): data(val), left(NULL), right(NULL) {}
};

void preorder(Node *root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}

void inorder(Node *root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}

deque<Node *> dq;
void levelorder(Node *root){
    dq.push_back(root);

    while(!dq.empty()){
        root = dq.front();
        dq.pop_front();

        if(!root) continue;

        cout<<root->data<<" "; 
        dq.push_back(root->left);
        dq.push_back(root->right);
    }

}

int height(Node *root, int &Diameter){
    if(root==NULL) return -1;
    int heightLeft = height(root->left, Diameter);
    int heightRight = height(root->right, Diameter);
    Diameter = max(Diameter, heightLeft+heightRight+2);
    return (max(heightLeft,heightRight)+1);
}
int diameter(Node *root){
    int Diameter=0;
    int h = height(root,Diameter);
    return Diameter;
}
