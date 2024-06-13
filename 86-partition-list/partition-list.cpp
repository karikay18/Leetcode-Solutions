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
    ListNode* partition(ListNode* head, int x) {
        ListNode *anshead= new ListNode (-1);
        ListNode *less=anshead;
        ListNode *cur=head;
        while(cur!=NULL)
        {
            if(cur->val<x)
            {
                less->next=new ListNode(cur->val);
                less=less->next;
            }
            cur=cur->next;
        }
        cur=head;
        while(cur!=NULL)
        {
            if(cur->val>=x)
            {
                less->next=new ListNode(cur->val);
                less=less->next;
            }
            cur=cur->next;
        }
        return anshead->next;

    }
};