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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next || !head->next->next)
            return NULL;
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        
        while(fast)
        {
            fast = fast->next;
            slow = slow->next;
            
            if(fast)
                fast = fast->next;
            else
                return NULL;
            
            if(fast==slow)
                break;
        }
        
        if(fast!=slow)
            return NULL;
        
        fast = head;
        
        while(fast!=slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        return slow;
    }
};