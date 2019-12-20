class Solution {
  public int evalRPN(String[] tokens) {
      int a,b;
      Stack<Integer> stack = new Stack<Integer>();
      for(String s: tokens){
          if(s.equals("+")){
              stack.add(stack.pop() + stack.pop());
          } else if(s.equals("-")){
              a = stack.pop();
              b = stack.pop();
              stack.add(b - a);
          } else if(s.equals("/")){
              a = stack.pop();
              b = stack.pop();
              stack.add(b / a);
          } else if(s.equals("*")){
              stack.add(stack.pop() * stack.pop());
          } else {
              stack.add(Integer.parseInt(s));
          }
      }
      return stack.pop();
  }
}