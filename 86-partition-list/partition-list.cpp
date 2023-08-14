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
        vector<int> v1, v2;
        for(auto it=head;it;it=it->next){
            if(it->val<x) v1.push_back(it->val);
            else v2.push_back(it->val);
        }
        ListNode* dummy=new ListNode(-1);
        ListNode* tail=dummy;
        for(int i=0;i<v1.size();i++){
            ListNode* newnode= new ListNode(v1[i]);
            tail->next= newnode;
            tail=newnode;
        }
        for(int i=0;i<v2.size();i++){
            ListNode* newnode= new ListNode(v2[i]);
            tail->next= newnode;
            tail=newnode;
        }
        return dummy->next;
    }
};