#include "../leetlib.h"
#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        //使用map键值对包,处理数值为负数的情况
        map<int,vector<int>> hash;           //注意此处如果使用vector,数组长度需要比最大值大1,否则会导致下标越界
        for(int i=0; i<nums.size(); i++){
            vector<int> temp = {i};
            hash.insert(pair<int,vector<int>>(nums[i],temp));
        }

        for(int i=0; i<nums.size(); i++)    
        {
            int res = target-nums[i];
            if (hash[res].size() != 0)
            {
                if (hash[res][0] != i)
                {
                    vector<int> ans = {i,hash[res][0]};
                    return ans;
                }
                else
                {
                    if (hash[res].size() > 1)
                    {
                        vector<int> ans = {i,hash[res][1]};      //注意此处复制的代码需要修改下标由0变1
                        return ans;
                    }//注意此处不能由else,否则会导致循环提前结束
                }    
            }
        }
    vector<int> ans;
    return ans;        
    }
};

int main()
{
    //Data
    vector<int> nums = {3,2,4};
    //Data

    Solution S1;
    S1.twoSum(nums, 6);
}
