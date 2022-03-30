#include "../leetlib.h"
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    int GetCnt(string answerKey, char c, int k)
    {
        int i=0, j=k;
        int cnt = 0;
        int max = 0;

        while(j < answerKey.size())
        {
            for(int ind=i; ind<j; ind++)
                if (answerKey[ind] != c)
                    cnt++;
            
            if (cnt <= k)
            {
                if (j-i > max)
                    max = j-i;
                j++;
            }    
            else
            {
                if (cnt > k)
                    i++;
            }
        }
        return max;
    }

    int maxConsecutiveAnswers(string answerKey, int k) 
    {
       return max(GetCnt(answerKey,'T',k),GetCnt(answerKey,'F',k));
    }
};

int main()
{
    Solution S1;
    string str = "TTFF";
    S1.maxConsecutiveAnswers(str,2);
}