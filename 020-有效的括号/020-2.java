class Solution {
    
  private HashMap<Character, Character> map = new HashMap<>();
  
  public Solution(){
      map.put('(',')');
      map.put('[',']');
      map.put('{','}');
  }
  public boolean isValid(String s) {
      Stack<Character> stack = new Stack<>();
      int len = s.length();
      for(int i = 0; i<len;i++){
          char c = s.charAt(i);
          if(map.containsKey(c)){// 左括号
              stack.push(c);
          } else {
              if(stack.isEmpty()) return false;
              if(c != map.get(stack.pop())) return false;
          }
      }
      return stack.isEmpty();
  }
}