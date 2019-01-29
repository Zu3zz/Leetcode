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
	// 此solution执行时间为8ms
	// 有两种解法
	// 第0种：利用二叉搜索树的性质
	// 根据中序遍历 即先左儿子 再根节点 最后右儿子的顺序遍历树
	// 如果是一个二叉搜索树 那么结果得到的一个升序数组 但是这种方法时间复杂度较高
	// 第1种：也是利用二叉搜索树的性质
	// 维护当前的节点与一个最大值max与最小值min
	// 只要保证当前节点的值在max与min之间，那么就是一个二叉搜索树
	// 优先判断左节点 然后判断右节点 遍历所有的节点之后依旧正确那么就是一个二叉搜索树
	// 这种方法速度更快
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN,LONG_MAX);
    }
    bool isValid(TreeNode *root,long min,long max){
        if(!root) return true;
        if(root->val>=max || root->val<=min) return false;
        return isValid(root->left,min,root->val) && isValid(root->right,root->val,max);
    }
};