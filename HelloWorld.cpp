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

    vector<int> preordertravese();

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

class Solution {
public:
    string bfs(vector<string>& words, int index)
    {
        vector<string> que;
        que.push_back(words[index]);
        int trigger = 1;

        while(trigger != 0)
        {
            trigger = 0;                    //注意trigger位置，用于控制下轮大迭代的变量因置于大迭代位置
            
            int len = que.size();
            for(int i=0; i<len; i++)
            {
                string base = que[i]; 
                for (int j=0; j<words.size(); j++)
                {
                    if (words[j].size() - 1 == base.size() 
                        && words[j].substr(0,base.size()) == base)
                    {
                        que.push_back(words[j]);
                        trigger = 1;
                    }    
                }
            }
            if (trigger == 0)
                break;
            else
            {
                for(int i=0; i<len; i++)
                {
                    vector<string>::iterator ptr = que.begin();
                    que.erase(ptr+i);
                }
            }
        }
        string ans = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
        for(int i=0; i<que.size(); i++)
        {
            if(que[i] < ans)
                ans = que[i];
        }
        return ans;
    }

    string longestWord(vector<string>& words) 
    {
        string back = "";
        for(int i=0; i<words.size(); i++)
        {
            if (words[i].size() == 1)
            {
                string temp = bfs(words, i);
                if (temp > back)
                    back = temp;
            }
        }
        return back;
    }
};


int main()
{
    vector<int> temp = {1,2,3,NULL,4};
    Tree test(temp);
    vector<int> ans = test.preordertravese();
    cout<<"exit"<<endl;
}

