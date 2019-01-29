/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 这段代码我也不知道什么作用 反正写上就能从12ms提高到8ms 玄学？？？
// 貌似可以解除cin与stdin的同步 加快读写数据的速率（我佛了
const static auto io_speed_up = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
	/* 此solution执行时间为8ms
	共有两种做法
	第0种 从p,q两个子节点从下往上找自己的父亲节点 并且将路径记录为一个序列，找到两个序列的LCA
	即最长公共子节点 但是树的数据结构中并没有提供从孩子节点指向父亲节点的指针 这样做难度较大
	第1种 使用递归的方法 核心思想如下
	既然root节点左右分别有p,q 那么当寻找root节点的左孩子 发现没有找到p,q时 
	那么说明root节点的左孩子节点不用再去寻找 直接从root节点的右孩子继续寻找即可
	如果左右分别都找到了p和q,那么说明此时的root就是我们需要的最近公共子序列的头结点 直接返回即可
	*/
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == q || root == p){
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left,p,q);
        TreeNode *right = lowestCommonAncestor(root->right,p,q);
        return left==NULL ? right : right==NULL? left: root;
    }
};