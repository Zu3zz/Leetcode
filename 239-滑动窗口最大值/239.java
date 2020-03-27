class Solution {
  public int[] maxSlidingWindow(int[] nums, int k) {
      Deque<Integer> queue = new LinkedList<>();
      int[] res = new int[nums.length - k + 1];
      int index = 0;
      for(int i = 0;i<nums.length;i++){
          while(!queue.isEmpty() && nums[queue.peekLast()] <= nums[i]){
              queue.pollLast();
          }
          queue.addLast(i);
          if(queue.peekFirst() == i - k){
              queue.pollFirst();
          }
          if(i >= k - 1){
              res[index++] = nums[queue.peekFirst()];
          }
      }
      return res;
  }
}