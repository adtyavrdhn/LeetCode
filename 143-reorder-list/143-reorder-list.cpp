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
     ListNode* f(ListNode* curr, ListNode* prev)
    {
        if(!curr)
        {
            return prev;
        }
        ListNode* next = curr->next;
        
        curr->next = prev;
        
        return f(next,curr);
    }
    void reorderList(ListNode* head) 
    {
        int count = 0;
        
        ListNode* p = head;
        while(p)
        {
            p=p->next;
            count++;
        }
        
        // we got total number of nodes, now we will seperate the list into two parts and reverse the second part then interweave them together
        
        ListNode* first = head;
        
        ListNode* second;
        
        int n = (count+1)/2;
        
        p = head;
        ListNode* q = NULL;
        
        while(n--)
        {
            q = p;
            p=p->next;
        }
        
        // cout<<q->val<<endl;
        second = q->next;
        q->next = NULL;
        
        second = f(second,NULL);
        
        p = first, q = second;
        
//         while(p)
//         {
//             cout<<p->val<<" ";
//             p=p->next;
//         }
        
//         cout<<endl;
        
//         while(q)
//         {
//             cout<<q->val<<" ";
//             q=q->next;
//         }
        
//         p = NULL, q = NULL;
        
        while(first && second)
        {
            p = first->next;
            first->next = second;
            q = second->next;
            second->next = p;
            
            first = p, second = q;
        }
            
    }
};