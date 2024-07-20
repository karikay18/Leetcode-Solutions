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
    ListNode* removeZeroSumSublists(ListNode* head) {
        // unordered_map<int,ListNode*>mpp;
        unordered_map<int, ListNode*> mpp;
         ListNode* dum=new ListNode(0);
         dum->next=head;
         mpp[0]=dum;
         int pre=0;
         while(head!=NULL)
         {
            pre+=head->val;
            if(mpp.find(pre)!=mpp.end())
            {
                ListNode* start=mpp[pre];
                ListNode* temp=start;
                int pf=pre;
                while(temp->next!=head)
                {
                    temp=temp->next;
                    pf+=temp->val;
                    mpp.erase(pf);
                }
                start->next=head->next;


            }
            else
            {
                mpp[pre]=head;
            }
            head=head->next;
         }
         return dum->next;
    }
};