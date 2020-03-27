class Solution {
  public int[] dailyTemperatures(int[] T) {
      Stack<Integer> stack = new Stack<>();
      int n = T.length;
      int[] res = new int[n];
      for(int i = 0;i<n;i++){
          while(!stack.isEmpty() && T[i] > T[stack.peek()]){
              int tmp = stack.pop();
              res[tmp] = i - tmp;
          }
          stack.push(i);
      }
      return res;
  }
}

