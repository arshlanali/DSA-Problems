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
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root || root==p ||  root==q) return root;
        TreeNode* left= lca(root->left, p, q);
        TreeNode* right= lca(root->right, p, q);
        if(left && right) return root;
        else if(left) return left;
        else if(right) return right;
        else return NULL;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> deepest;
        while(q.size()){
            int sz= q.size();
            vector<TreeNode*> temp;
            for(int i=0; i<sz;i++){
                TreeNode* node= q.front();
                temp.push_back(node);
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            deepest= temp;
        }
        TreeNode* res=deepest[0];
        for(int i=1; i<deepest.size(); i++){
            res= lca(root, deepest[i], res);
        }
        return res;
    }
};