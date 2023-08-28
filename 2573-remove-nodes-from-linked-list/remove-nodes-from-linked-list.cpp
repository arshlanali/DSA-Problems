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
        vector<int> nodes;
        for(auto it= head; it;it=it->next){
            nodes.push_back(it->val);
        }
        stack<int> st;
        vector<int> res;
        for(int i= nodes.size()-1;i>=0; i--){
            while(st.size() && st.top()<= nodes[i]) st.pop();
            if(st.empty()) res.push_back(nodes[i]);
            st.push(nodes[i]);
        }
        ListNode* dummy= new ListNode(-1);
        ListNode* tail= dummy;
        for(int i= res.size()-1; i>=0; i--){
            ListNode*  newnode= new ListNode(res[i]);
            tail->next= newnode;
            tail= newnode;
        }
        return dummy->next;
    }
};