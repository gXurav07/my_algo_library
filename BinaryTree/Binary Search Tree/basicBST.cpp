#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    long long  data;
    Node *left, *right;

    Node(long long val=0): data(val), left(NULL), right(NULL) {}
};

// value of pointer variable changed inside function not reflected outside. So, we need reference to pointer
void myInsertBST(Node *&root, long long val){ 
    if(root==NULL){
        root = new Node(val);
        return;
    }
    if(root->data>val){
        if(root->left==NULL) root->left = new Node(val);
        else myInsertBST(root->left,val);
    }
    else{
        if(root->right==NULL) root->right = new Node(val);
        else myInsertBST(root->right,val);
    }
    return;

}

// Conplexity = O(height)
Node* insertBST(Node *root, long long val){
    if(root==NULL){
        root = new Node(val);
        return root;
    }

    if(val<root->data) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}


// Conplexity = O(height)
Node* searchInBST(Node *root, long long val){
    if(root==NULL) return NULL;
    if(root->data==val) return root;
    if(val<root->data) return searchInBST(root->left,val);
    return searchInBST(root->right,val);
}
Node *inorderSucc(Node *root){
    root = root->right;
    if(root==NULL) return root;  // this is generally not the case

    while(root->left){
        root= root->left;
    }
    return root;
}

Node* deleteInBST(Node *root, long long val){
    if(root==NULL) return NULL;
    if(root->data>val) root->left = deleteInBST(root->left,val);
    else if(root->data<val) root->right = deleteInBST(root->right,val);
    else{
        if(root->right==NULL){
            Node *temp = root->left;
            delete(root);
            return temp;
        }
        if(root->left==NULL){
            Node *temp = root->right;
            delete(root);
            return temp;
        }

        Node *temp = inorderSucc(root);
        root->data=temp->data;
        root->right = deleteInBST(root->right,temp->data); // delete the inorder successor


    }
    return root;
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

vector<int> isBST(Node *root){
    if(root==NULL) return {1,-1,-1};
    vector<int> rr = isBST(root->left), lr = isBST(root->right),ans={0,(int)root->data,(int)root->data};

    if(lr[1]>=0) ans[1] = lr[1];
    if(rr[2]>=0) ans[2] = rr[2];

    if(!rr[0]) return ans;
    if(!lr[0]) return ans;
    if(root->data<lr[2]) return ans;
    if(root->data>rr[1]) return ans;

    ans[0]=1;
    return ans;
  
}

// optimised
bool isValidBST(Node *root, long long minAllowed, long long maxAllowed){

    if(root==NULL) return true;
    if(root->data<minAllowed) return false;
    if(root->data>maxAllowed) return false;

    bool chekLeft = isValidBST(root->left,minAllowed,root->data-1);
    bool chekRight = isValidBST(root->right,root->data+1,maxAllowed);

    return ((chekLeft)&&(chekRight));
}

int main(){
    Node *root=NULL;
    myInsertBST(root,6);
    myInsertBST(root,5);
    myInsertBST(root,11);
    myInsertBST(root,9);
    myInsertBST(root,8);
    myInsertBST(root,10);
    myInsertBST(root,14);
    myInsertBST(root,13);
    myInsertBST(root,15);

    levelorder(root);

    if(searchInBST(root,9)) cout<<"exists"<<endl;
    else cout<<"doesn't exist\n";

    deleteInBST(root,11);
    deleteInBST(root,9);
    levelorder(root);
    cout<<endl;
    cout<<isValidBST(root,-1,1e9)<<endl;
    root->right->left->data=3;
    cout<<isValidBST(root,-1,1e9)<<endl;
}
