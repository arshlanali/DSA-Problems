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
int n;
public:
    TreeNode* solve(int pres, int ins, int ine, vector<int> pre, vector<int> in){
        if(pres>=n || ins>ine) return NULL;
        TreeNode* root= new TreeNode(pre[pres]);
        int rootpos=n;
        for(int i=ins;i<=ine;i++) if(in[i]==root->val) rootpos=i;
        root->left= solve(pres+1, ins, rootpos-1, pre, in);
        root->right= solve(pres+ rootpos-ins+1, rootpos+1, ine, pre, in);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n= inorder.size();
        return solve(0, 0, n-1, preorder, inorder);
    }
};