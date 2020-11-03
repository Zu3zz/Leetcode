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
  public boolean isValidBST(TreeNode root){
    if(root == null) return true;
    return valid(root, null, null);
  }
  private boolean valid(TreeNode node, Integer lower, Integer upper){
    if(node == null) return true;

    int val = node.val;

    if(lower != null && val <= lower) return false;
    if(upper != null && val >= upper) return false;

    if(!valid(node.left, lower, val)) return false;
    if(!valid(node.right, val, upper)) return false;

    return true;
  }
}