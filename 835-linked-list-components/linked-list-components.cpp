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
    int numComponents(ListNode* head, vector<int>& nums) {
        if(!head ) return 0;
        unordered_set<int> st(nums.begin(), nums.end());
        int cnt=0;
        for(auto it=head;it;){
            if(st.find(it->val)!=st.end()){
                cnt++;
                while(it->next && st.find(it->val)!=st.end()) it=it->next;
            }
            it=it->next;
        }
        return cnt;
    }
};