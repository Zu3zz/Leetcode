/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int count = 0;
    
    int dfs(TreeNode* rt,int value){
        if(rt == NULL) return 0;
        int l = dfs(rt->left, rt->val);
        int r = dfs(rt->right, rt->val);
        count = max(count, l + r);
        if(rt->val == value)
            return max(l,r) + 1;
        else
            return 0;
    }
    
    int longestUnivaluePath(TreeNode* root) {
        if(root == NULL) return 0;
        dfs(root,root->val);
        return count;
    }
};