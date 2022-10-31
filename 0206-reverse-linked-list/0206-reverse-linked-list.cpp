/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* reverseList(ListNode *head)
        {
            return f(head, NULL);
        }
    ListNode* f(ListNode *p, ListNode *q)
    {
        if (!p)
        {
            return q;
        }

        ListNode *next = p->next;
        p->next = q;
        return f(next, p);
    }
};