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
    ListNode* swapNodes(ListNode* head, int k) 
    {
        int n = k - 1;
        
        ListNode* p = head;
        ListNode* first = NULL;
        
        while(n--)
        {
            p=p->next;
        }
        
        first = p;
        ListNode* fast = NULL;
        ListNode* slow = head;
        fast = p;
        
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode* second = slow;
        
        swap(first->val,second->val);
        
        return head;
    }
};