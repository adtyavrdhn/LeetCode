/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* l = dummy;
        ListNode* r = head;
        
        while(n-- && r)
        {
            r = r->next;
        }
        
        while(r)
        {
            r = r->next;
            l = l->next;
        }
        
        l->next = l->next->next;
        
        return dummy->next;
    }
};