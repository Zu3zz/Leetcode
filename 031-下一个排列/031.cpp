class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int j,len=nums.size(),i=len-1,tmp;
        while(i>0 && nums[i]<=nums[i-1])i--;
        if(i>0){
            j=len-1;
            while(j>=i && nums[j]<=nums[i-1])j--;
            tmp=nums[i-1];
            nums[i-1]=nums[j];
            nums[j]=tmp;
        }
        j=len-1;
        while(i<j){
            tmp=nums[i];
            nums[i]=nums[j];
            nums[j]=tmp;
            i++;j--;
        }
    }
};