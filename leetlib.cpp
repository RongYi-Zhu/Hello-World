#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include "leetlib.h"
using namespace std;

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

vector<int> Tree::preordertravese()
{
    vector<int> ans;
    stack<Treenode*> stk;
    Treenode* ptr = root;

    while(!stk.empty() || ptr != nullptr)
    {
        if (ptr != nullptr)
        {
            stk.push(ptr);
            ans.push_back(ptr->val);
            ptr=ptr->left;
        }
        else
        {
            ptr = stk.top()->right;
            stk.pop();
        }
    }
    return ans;    
}