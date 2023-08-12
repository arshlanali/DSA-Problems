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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy= new ListNode(-1);
        ListNode* tail=dummy;
        for(auto it=head;it;){
            while(it && it->val==0) it=it->next;
            int sum=0;
            while(it && it->val!=0) {
                sum+= it->val;
                it=it->next;
            }
            if(sum!=0) {
                ListNode* newnode= new ListNode(sum);
                tail->next=newnode;
                tail=newnode;
            }
        }
        return dummy->next;
    }
};