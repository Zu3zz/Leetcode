class Solution {
public:
	// 本题为执行时间为8ms的解
	// 想到三种方法 1.暴力两次循环 但是会遇到很多边界以及[3,3] 6 这样的问题 非常不推荐
	// 2.排序 时间复杂度为O(n*logn)
	// 3.使用map这种数据结构 将值与下标一一对应 循环一遍 查找对应的值是否在map中存在
	// 在使用一个数组用于存储结果
	// 使用第三种可以达到O(n)的时间复杂度
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> map1;
        vector<int> result;
        for(int i = 0;i<nums.size();i++){
            map1[nums[i]] = i;
        }
        for(int i =0;i<nums.size();i++){
            int res = target - nums[i];
            if(map1.count(res) && map1[res] != i){
                result.push_back(i);
                result.push_back(map1[res]);
                break;
            }
        }
        return result;
    }
};