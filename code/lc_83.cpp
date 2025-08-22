#include <iostream>
#include <stdio.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        // 哨兵
        ListNode sb = ListNode(-101, head);
        ListNode *cur = head;
        ListNode *pre = &sb;
        while (cur != nullptr)
        {
            if (cur->val == pre->val)
            {
                pre->next = cur->next;
                cur = cur->next;
            }
            else
            {
                pre = cur;
                cur = cur->next;
            }
        }
        return sb.next;
    }
};

int main()
{
    printf("hello world");
    return 0;
}