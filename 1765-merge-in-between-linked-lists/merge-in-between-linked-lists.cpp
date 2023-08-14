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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        a--;
        ListNode* t1=list1, *t2=list1, *tail=list2;
        while(t1 && a--) t1=t1->next;
        while(t2 && b--) t2=t2->next;
        for(auto it=list2;it;it=it->next) tail=it;
        t1->next=list2;
        tail->next=t2->next;
        return list1;
    }
};