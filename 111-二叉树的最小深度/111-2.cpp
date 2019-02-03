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
是111-1解的优化版 通过一个三目运算符 直接返回结果
大题思想与上一个相同
总共花费4ms的执行时间
*/

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        return (left == 0 || right == 0)? left + right + 1: min(left,right)+1;
    }
};