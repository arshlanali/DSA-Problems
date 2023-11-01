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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> hash;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            TreeNode* node= q.front();
            q.pop();
            hash[node->val]++;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        int maxi=0;
        for(auto it: hash){
            maxi= max(maxi, it.second);
        }
        vector<int> res;
        for(auto it:hash){
            if(it.second==maxi) res.push_back(it.first);
        }
        return res;
    }
};