class Solution {
  public List<Integer> topKFrequent(int[] nums, int k) {
      HashMap<Integer, Integer> map = new HashMap<>();
      
      for(int num:nums){
          if(map.containsKey(num)){
              map.put(num, map.get(num) + 1);
          }else{
              map.put(num,1);
          }
      }
      
      PriorityQueue<Integer> heap = new PriorityQueue<>(new Comparator<Integer>(){
          @Override
          public int compare(Integer a, Integer b){
              return map.get(a) - map.get(b);
          }
      });
      for(int key:map.keySet()){
          if(heap.size() < k){
              heap.add(key);
          } else if(map.get(key) > map.get(heap.peek())) {
              heap.remove();
              heap.add(key);
          }
      }
      LinkedList<Integer> res = new LinkedList<>();
      while(!heap.isEmpty()){
          res.add(heap.remove());
      }
      return res;
  }
}