/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 依旧是神奇的黑科技 用了之后从击败97%的20ms直接提高到击败100%的12ms
const static auto io_speed_up = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
	/*
	本solution正常是20ms的执行时间 加了黑科技代码后提高到了12ms的执行时间
	此题可以可用二叉搜索树本身的性质
	由于左子树中所有元素均比根节点小 右子树中所有节点均比根节点的值要大
	所以当根节点的val值比q,p都大时，说明q,p都在root节点的左子树里 所以直接返回root->left,p,q比较即可
	当root的val值比p,q都小时 说明q,p都在root节点的右子树里
	如果上述两个条件都不成立，那么说明此时 q,p一个在左子树里 一个在右子树里 最近公共节点已经找到 就是root
	*/
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        if(root->val < p->val && root->val < q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        return root;
    }
};