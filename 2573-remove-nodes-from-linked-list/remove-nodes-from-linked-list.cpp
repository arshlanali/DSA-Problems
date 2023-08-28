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
    ListNode* removeNodes(ListNode* head) {
        ListNode* curr= head, *prev= NULL;
        while(curr){
            ListNode* next= curr->next;
            curr->next= prev;
            prev=curr;
            curr=next;
        }
        for(auto it= prev; it->next;){
            if(it->val> it->next->val) it->next= it->next->next;
            else it=it->next;
        }
        curr= prev, prev=NULL;
        while(curr){
            ListNode* next= curr->next;
            curr->next= prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};