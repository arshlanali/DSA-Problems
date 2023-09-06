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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int sz=0;
        for(auto it=head;it;it=it->next) sz++;
        int len= sz/k;
        int extra=0;
        if(sz%k) extra= sz%k;
        ListNode* temp=head;
        vector<ListNode*> res;
        while(k--){
            if(!temp){
                res.push_back(NULL);
                continue;
            }
            ListNode* dummy= new ListNode(-1);
            ListNode* tail= dummy;
            for(int i=0;i<len;i++){
                tail->next=temp;
                tail=temp;
                temp=temp->next;
            }
            if(extra){
                tail->next=temp;
                tail=temp;
                temp=temp->next;
                extra--;
            }
            tail->next=NULL;
            res.push_back(dummy->next);
        }
        return res;
    }
};