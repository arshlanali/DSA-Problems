/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int last=INT_MIN, cnt=0, maxi=INT_MIN;
    void helper(TreeNode* root, vector<int>& res){
        if(!root) return ;
        helper(root->left, res);
        if(last== root->val) cnt++;
        else cnt=1;
        if(cnt>maxi){
            maxi= cnt;
            res.clear();
            res.push_back(root->val);
        }
        else if(cnt==maxi) res.push_back(root->val);
        last=root->val;
        helper(root->right, res);


    }
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
};