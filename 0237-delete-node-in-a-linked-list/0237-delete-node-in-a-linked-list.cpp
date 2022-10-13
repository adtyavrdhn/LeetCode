/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) 
    {
        ListNode* p = node;
        ListNode* q = node->next;
        ListNode* r;
        
        while(q)
        {
            p->val = q->val;
            r = p;
            p=p->next;
            q=q->next;
        }
        r->next = NULL;
    }
};