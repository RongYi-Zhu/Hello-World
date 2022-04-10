#ifndef LEETLIB_H
#define LEETLIB_H
#include<vector>
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

    vector<int> preordertravese();

private:
    Treenode* root;
};

class ListNode
{
public:
ListNode() : val(0), next(nullptr) {}
ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}

int val;
ListNode* next;
};

#endif