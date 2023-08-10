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
    int gcd(int a, int b){
        if(a==0) return b;
        return gcd(b%a, a);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* curr=head->next, * prev= head;
        while(prev && curr){
            // cout<<gcd(prev->val, curr->val)<<" ";
            ListNode* newnode= new ListNode(gcd(prev->val, curr->val));
            prev->next=newnode;
            newnode->next= curr;
            prev= curr;
            curr=curr->next;
        }
        return head;
    }
};