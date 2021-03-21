#include<bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    struct node * left,*right;
}*p,*q;

node * getnode(int x)
{
    q=new node();
    q->val=x;
    q->left=NULL;
    q->right=NULL;
    return q;
}

int countleaves(struct node * root)
{
    if(root==NULL)                                             
        return 0;
    if(root->left==NULL && root->right==NULL)               
        return 1;
    return (countleaves(root->left)+countleaves(root->right));  
}


int main()
{
    struct node * root=getnode(1);
    root->left=getnode(2);
    root->right=getnode(3);
    root->left->left=getnode(4);
    root->left->right=getnode(5);
    root->right->left=getnode(6);
    root->right->right=getnode(7);
    root->left->left->right=getnode(8);
    cout<<"Number of leaves in given tree is:\n";
    cout<<countleaves(root);
}