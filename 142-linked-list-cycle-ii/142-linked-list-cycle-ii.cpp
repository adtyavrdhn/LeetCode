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
        
        ListNode* tortoise = head;
        ListNode* hare = head;
        
        
        while(hare->next && hare->next->next)
        {
            tortoise = tortoise->next;
            hare = hare->next->next;
            
          if(hare == tortoise)
              break;
        }
        
        if(hare != tortoise)
            return NULL;
        hare = head;
        
        while(tortoise != hare)
        {
            tortoise = tortoise->next;
            hare = hare->next;
        }
        
        return tortoise;
    }
};