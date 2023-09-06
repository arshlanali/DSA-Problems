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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> mat(m, vector<int>(n, -1));
        ListNode* temp=head;
        int top=0, bot=m-1, left=0, right=n-1;
        int ind=0;
        while(top<=bot && left<=right){
            if(!head) break;
            if(ind==0){
                for(int i=left;i<=right;i++){
                    if(!head) break;
                    mat[top][i]=head->val;
                    head=head->next;
                }
                if(!head) break;
                top++;
                ind++;
            }
            if(!head) break;
            else if(ind==1){
                for(int i=top;i<=bot;i++){
                    if(!head) break;
                    mat[i][right]=head->val;
                    head=head->next;
                }
                if(!head) break;
                right--;
                ind++;
            }
            if(!head) break;
            else if(ind==2){
                for(int i=right;i>=left;i--){
                    if(!head) break;
                    mat[bot][i]=head->val;
                    head=head->next;
                }
                if(!head) break;
                bot--;
                ind++;
            }
            if(!head) break;
            else{
                for(int i=bot;i>=top;i--){
                    if(!head) break;
                    mat[i][left]=head->val;
                    head=head->next;
                }
                if(!head) break;
                left++;
                ind=0;
            }
            if(!head) break;
        }
        return mat;
    }
};