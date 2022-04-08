#include "../leetlib.h"
#include<string>
#include<queue>
#include<iostream>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        queue<Node*> que;
        vector<vector<int>> ans;
        Node* ptr = root;

        que.push(ptr);
        while ( !que.empty() )
        {
            vector<int> temp;
            int len = que.size();
            for(int i=0; i<len; i++)
            {
                temp.push_back(que.front()->val);
                for(int j=0; j<que.front()->children.size(); j++)
                {
                    if (que.front()->children[i] != nullptr)
                        que.push(que.front()->children[i]);
                }
                que.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

int main()
{
    Solution S1;

    //Data
    int k = 3;
    vector<int> arrival = {1,2,3,4};
    vector<int> load = {1,2,1,2};
    //Data


    return 0;
}