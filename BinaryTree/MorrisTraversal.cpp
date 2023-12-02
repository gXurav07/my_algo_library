#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    long long  data;
    Node *left, *right;

    Node(long long val=0): data(val), left(NULL), right(NULL) {}
};


// Iterative inorder Traversal
// Time Complexity: O(n)     Space Complexity: O(1)
void morrisTraversal(Node* root) {
    vector<int> ar;
    Node *cur=root,*temp=NULL;
    
    while(cur){
        if(!cur->left){
            cout<<cur->data<<" ";
            cur=cur->right;
        }
        else{
            temp=cur->left;

            // Find inorder predecessor of current Node
            while((temp->right)&&(temp->right!=cur)){ 
                temp=temp->right;
            }

            if(!temp->right){ 
                // create temporary link between inorder pred. and current Node
                temp->right=cur; 
                cur=cur->left;
            }

            else{
                // remove the temporary link when previous current is revisited from its left subtree through the temporary link
                temp->right=NULL; 
                cout<<cur->data<<" ";
                cur=cur->right;
            }
        }
    }
    cout<<endl;
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
    morrisTraversal(root);
 
    return 0;
}

// Time Complexity is O(n) because each node is visited atmost 3 times
// REASON: Path to inorder predecessor is unique for each node

/*
Our Tree:-

          5 
        /   \ 
       3     7 
      / \   / \ 
     2   4 6   8

*/