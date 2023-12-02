#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void print(){cout<<'\n';} 
template<typename T, typename ...TAIL>
void print(const T &t, TAIL... tail)
{
    cout<<t<<' ';
    print(tail...);
}

class Node{
public:
    int col; // 0: red, 1: black
    long long  data;
    Node *left, *right, *parent;
    Node(long long val=0, int color=0): col(color), data(val), left(NULL), right(NULL), parent(NULL) {}
};
void preorder(Node *root){
    if(root == NULL) return;

    cout<<root->data<<" ";
    if(root->col) cout<<"Black\n";
    else cout<<"Red\n";

    preorder(root->left);
    preorder(root->right);
    return;
}

void leftRotate(Node* root){
    if(root->right==NULL) return;

    Node *right = root->right;
    right->parent = root->parent;

    root->right = right->left;
    if(right->left) right->left->parent = root;

    right->left = root;
    if(root->parent){
        if(root->parent->left==root) root->parent->left=right;
        else root->parent->right=right;
    }
    root->parent = right;

    
    return;
}
void rightRotate(Node* root){
    if(root->left==NULL) return;

    Node *left = root->left;
    left->parent = root->parent;
    
    root->left=left->right;
    if(left->right) left->right->parent = root;

    left->right = root;

    if(root->parent){
        if(root->parent->left==root) root->parent->left=left;
        else root->parent->right=left;
    }

    root->parent = left;

    return;
}


void fixRBTree(Node *Z){
    if(Z->parent==NULL){
        Z->col=1;
        return;
    }

    if(Z->parent->col==1) return;

    Node *G, *P, *U;

    P = Z->parent;
    G = P->parent; 
    // G is never null because in that case P is root and Black in color
    //(Black chaeck of P done above already)

    if(G->left==P) U = G->right;
    else U = G->left;



    if((U!=NULL)&&(U->col==0)){  // Uncle is red
        G->col = 0;
        U->col = 1;
        P->col = 1;
        fixRBTree(G);
    }
    else{                        // Uncle is Black
        if((G->right==P)&&(P->left==Z)){
            rightRotate(P);
            fixRBTree(P);
        }
        else if((G->left==P)&&(P->right==Z)){
            leftRotate(P);
            fixRBTree(P);
        }
        else if((G->right==P)&&(P->right==Z)){
            leftRotate(G);
            P->col=1;
            G->col=0;
        }
        else if((G->left==P)&&(P->left==Z)){
            rightRotate(G);
            P->col=1;
            G->col=0;
        }

    }
    return;

}

Node* searchInRBTree(Node *root, long long val){
    if(root==NULL) return NULL;
    if(root->data==val) return root;
    if(val<root->data) return searchInRBTree(root->left,val);
    return searchInRBTree(root->right,val);
}




Node* insertInRBTree(Node* root,ll val, Node *parent = NULL){
    
    if(root==NULL){
        root = new Node(val);  // This is the line that requires node to be passed as reference  
        root->parent = parent;
        if(parent){
            if(parent->data>val) parent->left=root;
            else parent->right=root;
        }


        fixRBTree(root);

        while(root->parent){
            root=root->parent;
        }
        return root;
    }

    if(val<root->data) return insertInRBTree(root->left, val,root);
    else if(val>root->data) return insertInRBTree(root->right, val,root);
    else{
        while(root->parent){
            root=root->parent;
        }
        return root;
    }

    return NULL;
}

Node *inorderSucc(Node *root){
    root = root->right;
    if(root==NULL) return root;  // this is generally not the case

    while(root->left){
        root= root->left;
    }
    return root;
}

bool hasRedChild(Node *Y){
    if((Y->right)&&(Y->right->col==0)) return 1;
    if((Y->left)&&(Y->left->col==0)) return 1;
    return 0;
}

void resolveDB(Node *Z){
    if(Z->parent==NULL) { // If Z is the root node
        Z->col = 1;
        return;
    }
    Node *P, *Y;
    P = Z->parent;
    if(P->left==Z) Y = P->right;
    else Y = P->left;

    if((Y->col)&&(hasRedChild(Y))){  // Case 1
        if((P->right==Y)&&(Y->right)&&(Y->right->col==0)){
            Node *X = Y->right;
            leftRotate(P);
            swap(P->col,Y->col);
            Z->col=1;
            X->col=1;
            return;
        }
        
        if((P->left==Y)&&(Y->left)&&(Y->left->col==0)){
            Node *X = Y->left;
            rightRotate(P);
            swap(P->col,Y->col);
            Z->col=1;
            X->col=1;
            return;
        }

        if((P->right==Y)&&(Y->left)&&(Y->left->col==0)){
            Node *X = Y->left;
            rightRotate(Y);
            swap(Y->col,X->col);
            resolveDB(Z);
            return;
        }

        if((P->left==Y)&&(Y->right)&&(Y->right->col==0)){
            Node *X = Y->right;
            leftRotate(Y);
            swap(Y->col,X->col);
            resolveDB(Z);
            return;
        }

    }
    else if(Y->col){   // Case 2
        if(P->col==0){
            P->col=1;
            Y->col=0;
            Z->col=1;
            return;
        }
        else{
            P->col=2;
            Y->col=0;
            Z->col=1;
            resolveDB(P);
            return;
        }
    }
    else if(Y->col==0){  // Case 3
        if(P->left==Z){
            leftRotate(P);
            swap(P->col,Y->col);
            resolveDB(Z);
            return;
        }
        else{
            rightRotate(P);
            swap(P->col,Y->col);
            resolveDB(Z);
            return;
        }

    }
}


void DeleteNode(Node *root){
    Node *parent = root->parent;
    if(parent){
        if(parent->left==root) parent->left=NULL;
        else parent->right=NULL;
    }

    delete(root);
    return;
}

Node* deleteInRBTree(Node *root, int val, Node *parent=NULL){
    if(root==NULL){

        if(!parent) return NULL;

        root=parent;
        while(root->parent){
            root=root->parent;
        }
        return root;
    }

    if(root->data>val) return deleteInRBTree(root->left,val,root);
    else if(root->data<val) return deleteInRBTree(root->right,val,root);
    else{
        if((!root->left)&&(!root->right)){
            if(root->col==0){  // Case #0
                DeleteNode(root);
            }
            else{   // Main case
                root->col=2; // Double Black
                resolveDB(root);
                DeleteNode(root);
            }
            return deleteInRBTree(NULL,-1,parent);
        }
        if(!root->right){  // Case #1
            root->data=root->left->data;
            DeleteNode(root->left);
            return deleteInRBTree(NULL,-1,root);
        }
        if(!root->left){  // Case #1
            root->data=root->right->data;
            DeleteNode(root->right);
            return deleteInRBTree(NULL,-1,root);
        }

        Node *temp = inorderSucc(root);
        root->data = temp->data;
        return deleteInRBTree(root->right,temp->data,root);

    }
    return root;
}



int main(){
    Node *root=NULL;

    root=insertInRBTree(root,0);
    root=insertInRBTree(root,2);
    root=insertInRBTree(root,1);


    preorder(root);

    //cout<<searchInRBTree(root,1)<<endl;



    




    

    return 0;

}

/*
    insertInRBTree(root,6);
    insertInRBTree(root,5);
    insertInRBTree(root,11);
    insertInRBTree(root,9);
    insertInRBTree(root,10);
    insertInRBTree(root,4);
    insertInRBTree(root,1);
    insertInRBTree(root,15);
    */