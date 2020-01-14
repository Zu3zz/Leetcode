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
  public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
      List<List<Integer>> res = new ArrayList<>();
      searchTree(root, res, 0);
      return res;
  }
  public void searchTree(TreeNode root, List<List<Integer>> res,int level){
      if(root == null){
          return;
      }
      if(res.size() == level){
          res.add(new ArrayList<Integer>());
      }
      if((level & 1) == 1){
          res.get(level).add(0, root.val);
      } else {
          res.get(level).add(root.val);
      }
      searchTree(root.left, res, level + 1);
      searchTree(root.right, res, level + 1);
  }
}