/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
  public int index = 0;
  public int res = 0;
  public int kthSmallest(TreeNode root, int k) {
      if(root == null) return 0;
      index = k;
      dfs(root);
      return res;
  }
  public void dfs(TreeNode node){
      if(node == null || index < 0){
          return;
      }
      dfs(node.left);
      index--;
      if(index == 0){
          res = node.val;
      }
      dfs(node.right);
  }
}