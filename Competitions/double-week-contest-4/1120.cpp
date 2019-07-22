/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 输入：[5,6,1]
 * 输出：6.00000
 * 解释： 
 * 以 value = 5 的节点作为子树的根节点，得到的平均值为 (5 + 6 + 1) / 3 = 4。
 * 以 value = 6 的节点作为子树的根节点，得到的平均值为 6 / 1 = 6。
 * 以 value = 1 的节点作为子树的根节点，得到的平均值为 1 / 1 = 1。
 * 所以答案取最大值 6。
 * 使用dfs 运用pair存储个数和总和 ans 用来保存每次dfs过程中算出的平均值
 */
class Solution {
public:
    double ans = 0;
    pair<double, int> dfs(TreeNode* t){
      int count = 1;
      double rate = t->val;
      if(t->left){
        pair<double, int> res = dfs(t->left);
        count+=res.second;
        rate+=res.first;
      }
      if(t->right){
        pair<double, int> res = dfs(t->right);
        count+=res.second;
        rate+=res.first;
      }
      ans = max(ans, rate/(double)count);
      return make_pair(rate, count);
  }
  double maximumAverageSubtree(TreeNode* root) {
    pair<double, int> res = dfs(root);
    return ans;
  }
};