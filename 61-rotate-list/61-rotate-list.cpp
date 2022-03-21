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
    ListNode* rotateRight(ListNode* head, int k) 
    {
       if(!head || !head->next || k==0) return head;
        
        ListNode* p = head;
        int size = 1;
        
        while(p->next)
        {
            size++;
            p = p->next;
        }
        
        //loop the list
        p->next=head;
        
        //handle the case of k>size
        k = k%size;
        
        //find the node to break the loop at
        while(--size >= k)
        {
            p=p->next;
        }
        
        ListNode* first = p->next;
        p->next=NULL;
        
        return first;
    }
};