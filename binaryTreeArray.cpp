// If array  starts from 0 to n-1:
//     left child -> (2*p)+1 (p is parent)
//     right child -> (2*p)+2

// If array starts from 1 to n:
//     left child -> (2*p)
//     right child -> (2*p)+1


#include <iostream>
using namespace std;

class BinaryTree {
    int size;
   int *tree;
    public:
    BinaryTree(){
       this->tree = (int*) malloc(10* sizeof(int));
    }
     BinaryTree(int size){
        this->size= size;
        this->tree = (int*) malloc(size* sizeof(int));
    }
    void root(int key){
       if(this->tree[0] != '\0')
            cout<<"Tree already had root"<<endl;
        else
            tree[0]=key;
    }
    void add_left(int parent, int key){
        if(tree[parent] == '\0')
            cout<<"No parent found"<<endl;
        else 
            tree[(parent*2)+1] = key;
    }

    void add_right(int parent, int key){
        if(tree[parent] == '\0')
            cout<<"No parent found"<<endl;
        else 
            tree[(parent*2)+2] = key;
    }

    void display(){
        for(int i=0;i<size;i++){
            if(tree[i] != '\0')
                cout<<tree[i]<<" ";
            else
                cout<<"-"<<" ";
        }
    }

};

int main()
{
    BinaryTree tree(10);
    tree.root(1);
    tree.root(2);
    tree.add_right(0,1);
    tree.add_left(0,1);
    tree.add_left(2,5);
    tree.display();
    return 0;
}