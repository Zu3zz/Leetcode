class Solution {
public:
	// 这道题具有一定难度 本解答执行时间为80ms
	// 思路0 三重循环 不过时间复杂度会来到O(n^3) 复杂度爆炸

	// 思路1 既然需要找到三个对应和的数组元素 可以理解为首先确定两个元素 再找剩下的一个元素
	// 即确定x1,x2 在找-(x1+x2) 这样的话就需要两次for循环 外加一次leetcode-001中所使用到的技巧
	// 即将剩下的所有元素存成set 避免重复问题
	
	// 思路2 
	//（1）先对数组进行一次排序，按照从小到大的顺序
	//（2）第一次循环 从第一个到倒数第三个元素先确定第一个值x1
	//（3）将剩下的已经排好序的nums数组中的其他元素看做一个新的数组
	// 取出这个数组的第一个值和最后一个值x2 x3 由于已经经过排序 所以x2是最小值 x3是最大值
	//（4）此时将x1 x2 x3三者相加 看其值与0的大小关系 如果大于0 则将最大值x3往小的方向移动一位
	// 如果小于0 则说明x2过于小 往右边移动一位 
	// 不断重复次过程 直至两者相遇
	//（5）在这个过程中需要注意元素重复的问题 当遇到左右元素相同的时候 应该跳过相同元素直接指向下一个元素
	// 这样做的话可以有效避免解的重复问题
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());   //排序，从小到大
        for(int i = 0 ; i < n - 2; i ++){
            int j = i + 1;
            int k = n - 1;
            while(j < k){
                if(nums[i] + nums[j] + nums[k] > 0){
                     k --; 
                 }
                 else if(nums[i] + nums[j] + nums[k] < 0){
                     j ++;
                 }
                 else{
                     ans.push_back({nums[i], nums[j], nums[k]});
                     while(nums[j+1] == nums[j])   j++;// 避免重复
                     j ++;
                 }
            }
            while(nums[i+1] == nums[i])   i++;// 避免重复
        }
        // ans.erase(unique(ans.begin(),ans.end()),ans.end());
        // 直接在数组中去重的话无法解决([2,2,-4][-4,2,2])这种情况
        // 所以直接去重是不可取的 不过也可以将每一个数组中的数字做一次set
        // 不过这样做比较麻烦 而且意义不大
        return ans;
    }
};