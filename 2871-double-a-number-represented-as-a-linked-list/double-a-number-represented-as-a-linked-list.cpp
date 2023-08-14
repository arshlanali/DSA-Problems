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
    ListNode* doubleIt(ListNode* head) {
        ListNode* prev=NULL, *cur=head, *next;
        while(cur){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        int carry=0;
        // for(auto it=prev;it;it=it->next) cout<<it->val<<" ";
        ListNode* temp=prev;
        ListNode* curr=prev, * pre=NULL;
        while(curr){
            int sum=carry;
            sum+= curr->val*2;
            curr->val= sum%10;
            carry=sum/10;
            pre=curr;
            curr=curr->next;
        }
        if(carry){
            ListNode* newnode= new ListNode(1);
            pre->next=newnode;
        }
        prev=NULL;
        
        while(temp){
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        return prev;
    }
};