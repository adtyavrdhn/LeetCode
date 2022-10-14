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
    ListNode* deleteMiddle(ListNode* head) 
    {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        
        ListNode* p = head;
        
        while(p && p->next)
        {
            p=p->next;
            if(p)
            p=p->next;
            
            prev=prev->next;
        }
        
        prev->next = prev->next->next;
        
        return dummy->next;
    }
};