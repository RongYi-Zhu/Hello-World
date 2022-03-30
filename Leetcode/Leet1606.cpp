#include "../leetlib.h"
#include<string>
#include<iostream>
using namespace std;

class Solution 
{
public:
    int SeekAva(vector<int> server, int time, int index)
    {
        int num = 0, ans = index%server.size();
        while(num < server.size())
        {
            if (server[ans] <= time)
                return ans;
            num++;
            ans = (ans+1)%server.size();
        }
        return -1;
    }

    vector<int> VecMax(vector<int> arg)
    {
        int max = 0;
        vector<int> ans;
        for(int i=0; i<arg.size(); i++)
        {
            if (arg[i] > max)
            {
                ans.clear();
                ans.push_back(i);
                max = arg[i];
            }
            else
                if (arg[i] == max)
                    ans.push_back(i);
        }
        return ans;
    }

    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) 
    {
        vector<int> server(k,0);
        vector<int> num(k,0);

        for(int i=0; i<arrival.size(); i++)
        {
            int ans = SeekAva(server, arrival[i], i);
            if (ans > 0)
            {
                server[ans] = load[i] + arrival[i];
                num[ans]++;
            }       
        }
        return VecMax(num);
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

    S1.busiestServers(k,arrival,load);
}