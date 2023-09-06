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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* curr=head, * prev=NULL;
        while(curr){
            ListNode* next= curr->next;
            curr->next= prev;
            prev=curr;
            curr=next;
        }
        stack<int> st;
        vector<int> res;
        for(auto it=prev;it;it=it->next){
            while(st.size() && st.top()<= it->val) st.pop();
            if(st.size()) res.push_back(st.top());
            else res.push_back(0);
            st.push(it->val);
        }
        reverse(begin(res), end(res));
        return res;
    }
};