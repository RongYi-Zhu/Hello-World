#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<queue>
using namespace std;

class Treenode
{
public:
    Treenode():val(0),left(nullptr),right(nullptr){}
    Treenode(int x):val(x),left(nullptr),right(nullptr){}
    Treenode(int x,Treenode* l,Treenode* r):val(x),left(l),right(r){}

    int val;
    Treenode* left;
    Treenode* right;
};

class Tree
{
public:
    Tree(){root = nullptr;}
    Tree(Treenode* _root){root = _root;}
    Tree(vector<int> value);

private:
    Treenode* root;
};

Tree::Tree(vector<int> value)
{
    if (value.size() < 1)
        root = nullptr;

    Treenode* ptr;
    queue<Treenode*> head;
    root = new Treenode(value[0]);    //root should initialized when constructor begin
    head.push(root);
    
    int i= 1;

    while(i < value.size())
    {
        ptr = head.front();
        head.pop();
        
        if (value[i] != NULL)
        {
            ptr->left = new Treenode(value[i]);
            head.push(ptr->left);
        }
        if (value[i+1] != NULL && i+1 < value.size())
        {
            ptr->right = new Treenode(value[i+1]);
            head.push(ptr->right);
        }
        
        
        i = i+2;
    }
}


int main()
{
    vector<int> val = {3,9,20,NULL,NULL,15,7};
    Tree t(val);
    cout<<true<<endl;
}