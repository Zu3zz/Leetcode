class Solution {
  public int scoreOfParentheses(String S) {
      Stack<Character> stack = new Stack<>();
      char[] c = S.toCharArray();
      int len = c.length;
      if(len == 0) return 0;
      int sum = 0;
      boolean f = true;
      for(int i = 0; i < len; i++){
          if(c[i] == '('){
              stack.add(c[i]);
              f = true;
          } else {
              if(f){
                  sum+= Math.pow(2,stack.size()-1);
                  stack.pop();
                  f = false;
              } else{
                  stack.pop();
              }
          }
      }
      return sum;
  }
}