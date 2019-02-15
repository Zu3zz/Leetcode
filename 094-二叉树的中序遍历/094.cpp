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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        InOrder(root,res);
        return res;
    }
    void InOrder(TreeNode* root,vector<int> &res){
        if(root->left!=NULL) InOrder(root->left,res);
        res.push_back(root->val);
        if(root->right!=NULL) InOrder(root->right,res);
    }
};