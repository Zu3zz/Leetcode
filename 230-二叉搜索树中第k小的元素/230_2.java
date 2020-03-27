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
  public int kthSmallest(TreeNode root, int k) {
      int index = 0;
      Stack<TreeNode> s = new Stack<>();
      if(root == null) return 0;
      while(root != null || !s.isEmpty()){
          while(root != null){
              s.push(root);
              root = root.left;
          }
          root = s.pop();
          index++;
          if(index == k){
              return root.val;
          }
          root = root.right;
      }
      return 0;
  }
}