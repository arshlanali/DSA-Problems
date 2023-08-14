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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev=NULL;
        if(!head || !head->next) return head;
        for(auto it=head;it && it->next;it=it->next){
            bool flag=true;
            if(it->val==it->next->val){
                flag=false;
                while(it->next && it->val==it->next->val) it=it->next;
                if(prev){
                    prev->next=it->next;
                }
                else head=it->next;
            }
            if(flag) prev=it;
        }
        return head;
    }
};