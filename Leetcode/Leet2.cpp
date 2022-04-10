#include <string>
#include <iostream>
#include "../leetlib.h"
using namespace std;


ListNode* vector2list(vector<int> data)
{
    if (data.size() == 0)
        return nullptr;
    ListNode* ptr = new ListNode(data[0]);
    ListNode* head = ptr;

    for(int i=1; i<data.size(); i++)
    {
        ptr->next = new ListNode;
        ptr = ptr->next;
        ptr->val = data[i];
    }
    return head;
}

class Solution {
public:
    pair<int, int> add(int a, int b, int car)
    {
        return pair<int,int>((a+b+car)/10,(a+b+car)%10);        //此处出现错误,忘记加car
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        string a,b;
        ListNode* ptr = l1;
        while(ptr != nullptr)
        {
            a.append(to_string(ptr->val));
            ptr = ptr->next;
        }
        ptr = l2;
        while(ptr != nullptr)
        {
            b.append(to_string(ptr->val));
            ptr = ptr->next;
        }

        int lena = a.size(); int lenb = b.size();
        string ans;
        pair<int,int> temp(0,0);     //注意此句位置

        int ind_a=0,ind_b=0,i=0;
        while(ind_a<lena && lenb>ind_b)
        {
            
            temp = add(a[ind_a]-'0', b[ind_b]-'0', temp.first);              //char2int:-'0'
            ans.push_back(temp.second+'0');                 //int2char:+'0' 
            ind_a++; ind_b++;
        }

        
        while(ind_a < lena)
        {
            temp = add(a[ind_a]-'0',0,temp.first);
            ans.push_back(temp.second+'0');
            ind_a++;
        }
        while(ind_b < lenb)
        {
            temp = add(0,b[ind_b]-'0',temp.first);       //复制代码时记得检查是否功能完备
            ans.push_back(temp.second+'0');      //复制代码时记得修改所有参数
            ind_b++;
        }

        if (temp.first != '0')
            ans.push_back(temp.first+'0');
        
        ListNode* ans_ptr = new ListNode(ans[0]-'0');
        ListNode* head = ans_ptr;                      //注意此处 错误的将头指针和结果指针合并 导致结果 内存泄漏
        for(int i=1; i<ans.size(); i++)
        {
            ans_ptr->next = new ListNode;
            ans_ptr = ans_ptr->next;
            int temp = ans[i]-'0';
            ans_ptr->val = temp;
        }
        return head;
    }
};

int main()
{
    //data
    vector<int> list1={2,4,9};
    vector<int>  list2={5,6,4,9};
    
    ListNode* l1 = new ListNode;
    ListNode* l2 = new ListNode;

    l1 = vector2list(list1);
    l2 = vector2list(list2);
    //data

    Solution S1;
    ListNode* temp = S1.addTwoNumbers(l1,l2);
    cout<<"END"<<endl;
}