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
        if (head == nullptr)
            return nullptr;
        ListNode sb = ListNode(-101, head);
        ListNode res = ListNode(-101, 0);
        ListNode *slow = &res;
        ListNode *fast = head;
        ListNode *pre = &sb;

        // 每次遇到相同值把first置为false，first为true就可以 slow=pre
        bool first = false;
        while (fast != nullptr)
        {
            while (fast != nullptr && fast->val == pre->val)
            {
                first = false;
                fast = fast->next;
            }
            if (fast == nullptr)
                break;
            // fast停在第一个与前值不同的节点，如1 1 2 的2
            if (first)
            {
                slow->next = pre;
                slow->next->next = nullptr;
                slow = pre;
            }
            else
                first = true;

            pre = fast;
            fast = fast->next;
        }
        if (first)
        {
            slow->next = pre;
            slow->next->next = nullptr;
        }

        return res.next;
    }
};

int main()
{
    ListNode node5(5); // 最后一个节点
    ListNode node4_2(4, &node5);
    ListNode node4_1(4, &node4_2);
    ListNode node3_2(3, &node4_1);
    ListNode node3_1(3, &node3_2);
    ListNode node2(2, &node3_1);
    ListNode head(1, &node2); // 头节点

    ListNode *list = &head;

    Solution sl;
    sl.deleteDuplicates(list);

    return 0;
}