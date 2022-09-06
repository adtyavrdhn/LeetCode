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
        ListNode* mergeKLists(vector<ListNode*> &lists)
        {
            int n = lists.size();
            
            
            if (lists.size() == 0)
                return nullptr;

            if (lists.size() < 2)
                return lists[0];
            
            
            while (n > 1)
            {
                for (int i = 0; i < n / 2; i++)
                {
                    lists[i] = merge(lists[i], lists[n - i - 1]);
                }
                n = (n + 1) / 2;
            }

           return lists.front();
        }
    ListNode* merge(ListNode *p, ListNode *q)
    {
        if (!p)
            return q;

        if (!q)
            return p;

        ListNode *dummy = new ListNode(0);

        ListNode *temp = dummy;

        while (p && q)
        {
            if (p->val < q->val)
            {
                temp->next = p;
                p = p->next;
            }
            else
            {
                temp->next = q;
                q = q->next;
            }

            temp = temp->next;
        }
        if (p)
        {
            temp->next = p;
        }
        if (q)
        {
            temp->next = q;
        }

        return dummy->next;
    }
};