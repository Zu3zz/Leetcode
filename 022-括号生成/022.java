class Solution {
  private List<String> res;
  public List<String> generateParenthesis(int n) {
      res = new ArrayList<String>();
      generate(0, 0, n, "");
      return res;
  }
  public void generate(int left, int right, int n, String s){
      // terminator
      if (left == n && right == n){
          res.add(s);
          return;
      }
      
      // process left right
      
      // drill down
      if(left < n){
          generate(left + 1, right,n, s + "(");
      }
      if(left > right){
          generate(left, right + 1, n, s + ")");
      }
      
      // reverse states
  }
}