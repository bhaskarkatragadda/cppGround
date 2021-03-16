#include <bits/stdc++.h>
using namespace std;

//Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

//preoder traversal
vector <int> preoder(Node* root){
    vector<int> nodes;
    nodes.push_back(root->data);
    if(root->left!=NULL)
    for(auto it: preoder(root->left))
    nodes.push_back(it);
    if(root->right!=NULL)
    for(auto it: preoder(root->right))
    nodes.push_back(it);

    return nodes;
}
//inorder traversal
vector <int> inorder(Node* root){
    vector<int> nodes;
    if(root->left!=NULL)
    for(auto it: inorder(root->left))
    nodes.push_back(it);
     nodes.push_back(root->data);
     if(root->right!=NULL)
    for(auto it: inorder(root->right))
    nodes.push_back(it);

    return nodes;
}

//post order
vector <int> postorder(Node* root){
    vector<int> nodes;
    if(root->left!=NULL)
    for(auto it: postorder(root->left))
    nodes.push_back(it);
     if(root->right!=NULL)
    for(auto it: postorder(root->right))
    nodes.push_back(it);
    nodes.push_back(root->data);
    return nodes;
}

int getMax(Node* root){
    queue<Node *> q;
    if(root == NULL)
        return 0;
    q.push(root);
    Node *curr;
    int max = root->data;
    while(!q.empty()){
        curr=q.front();
        q.pop();
        if(curr->data > max)
            max = curr->data;
        if(curr->left != NULL)
            q.push(curr->left);
        if(curr->right != NULL)
            q.push(curr->right);
    }
    return max;
}
// Utility function to create a new Tree Node
Node* newNode(int val){
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to build tree
Node* buildTree(string str){
    //corner case
    if(str.length() == 0 || str[0] =='N')
        return NULL;

    // Creating a vector of strings from input string after
    // by space
    vector<string> ip;

    istringstream iss(str);
    for(string str;iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()){
        //Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        //If the left child is not null
        if(currVal != "N"){
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N"){

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

int main(){
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        vector<int> res1 = preoder(root);
        for(int i: res1)
            cout<<i<< " ";
        cout<<endl;

        vector<int> res2 = inorder(root);
        for(int i: res2)
            cout<<i<< " ";
        cout<<endl;

        vector<int> res3 = postorder(root);
        for(int i: res3)
            cout<<i<< " ";
        cout<<endl;

        int max = getMax(root);
        cout<<max<<endl;
    return 0;
}
