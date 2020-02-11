class Solution{
    public int thirdMax(int[] nums) {
        TreeSet<Integer> set = new TreeSet<>();
        for(int num:nums){
            set.add(num);
            if(set.size() > 3){
                set.remove(set.first());
            }
        }
        return set.size() < 3 ? set.last() : set.first();
    }
}