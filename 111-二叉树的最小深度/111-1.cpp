/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
执行时间为8ms
使用DFS的思想进行搜索
当根节点为空时 直接返回0
当左子树为空时 直接返回右子树+1
当右子树为空时 直接返回左子树+1
*/

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->right) return 1 + minDepth(root->left);
        if(!root->left) return 1 + minDepth(root->right);
        
        int min_left = minDepth(root->left);
        int min_right = minDepth(root->right);
        
        int result = 1 + min(min_left,min_right);
        
        return result;
    }
};