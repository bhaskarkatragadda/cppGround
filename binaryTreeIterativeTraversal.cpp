#include<bits/stdc++.h>
using namespace std;

struct node                                 //structure of tree defined
{
    int val;
    struct node * left,*right;
}*p,*q;

node * getnode(int x)                      // Return tree node with given value
{
    q=new node();
    q->val=x;
    q->left=NULL;
    q->right=NULL;
    return q;
}

stack<node *>s1;
void iterativeinorder(struct node *p)
{
    while(p!=NULL)
    {
        s1.push(p);                           //push current node in stack without printing
        p=p->left;                            //go to it's left until it becomes NULL
    }

    while(!s1.empty())                        //repeat the process until stack becomes empty
    {
        node *p=s1.top();
        s1.pop();                             //every time pop one element from stack
        cout<<p->val<<" ";
        p=p->right;                           //print current node and go to it's right
        while(p!=NULL)
        {
             s1.push(p);                      //push current node and go to it's left until becomes NULL
             p=p->left;
        }

    }
}

stack<node*>s;
void iterativepreorder(struct node * p)
{
    while(p!=NULL)                                      //print current value and go to it's left until it becomes NULL
    {
        cout<<p->val<<" ";
        if(p->right!=NULL)
            s.push(p->right);                           //if current node has right child, push into stack
        p=p->left;
    }
    while(!s.empty())                                   //repeat the process until stack becomes empty
    {
        node *p=s.top();                                //every time pop one element from stack and follow same steps
        s.pop();
        while(p!=NULL)
        {
            cout<<p->val<<" ";

            if(p->right!=NULL)
            {
                s.push(p->right);
            }

                p=p->left;
        }

    }
    cout<<endl;
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
    iterativeinorder(root);                
    iterativepreorder(root);                                    

}
