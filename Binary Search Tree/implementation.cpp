#include "bits/stdc++.h"
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insertIntoBST(Node* root, int d){
    if(root==NULL){
        root = new Node(d);
        return root;
    }

    if( d > root->data){
        // right part me insert karna h
        root->right = insertIntoBST(root->right, d);
    }

    else{
        // left part me insert karna h
        root->left = insertIntoBST(root->left, d);
    }

    return root;

}

void takeInput(Node* &root){
    
    int data;
    cin>>data;
    while(data!=-1){
        root = insertIntoBST(root, data);
        cin>>data;
    }
}
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<' ';
    inorder(root->right);
}

Node* deleteFromBST(Node* root, int val){
    if(root==NULL){
        return root;
    }
    if(root->data==val){

        // 0 child
        if(root->left==NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // 1 child
        if(root->left!=NULL && root->right==NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL && root->right!=NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if(root->left != NULL && root->right!=NULL){
            int mini = minVal(root->right) -> data;
            root->data = mini;
            root->right = deleteFromBST(root->right, min);
            return root;
        }
    }
    else if(root->data > val){
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else{
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}

signed main(){

    Node* root = NULL;
    cout<<"Enter data to create BST"<<endl;
    takeInput(root);
    inorder(root);

    int k; cin>>k;
    root = deleteFromBST(root,k );

    inorder(root);

    return 0;
} 