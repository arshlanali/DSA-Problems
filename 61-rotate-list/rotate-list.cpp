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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0) return head;
        if(!head or !head->next) return head;
        int sz=0;
        for(auto it=head;it;it=it->next) sz++;
        k=k%sz;
        if(sz==k || k==0) return head;
        cout<<sz<<" "<<k;
        ListNode* slow= head, *fast= head;
        while(fast && k--) fast=fast->next;
        while(fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* temp= slow->next;
        slow->next=NULL;
        // cout<<temp->val<<" ";
        // for(auto it=head;it;it=it->next) cout<<it->val<<" ";
        ListNode* t=temp;
        while(t->next) t=t->next;
        t->next=head;
        head= temp;
        return head;
    }
};