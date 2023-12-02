 #include <bits/stdc++.h>

using namespace std;

class Node{
public:
    long long  data;
    Node *left, *right;

    Node(long long val=0): data(val), left(NULL), right(NULL) {}
};
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