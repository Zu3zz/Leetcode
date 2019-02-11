static const auto io_speed_up = []()
    {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        return 0;
    }();
class Solution {
	/*
	执行时间为4ms
	第一种方法 二分法 找到无序的那部分 接着二分
	第二种方法 直接一遍搜索过
	*/
public:
    int search(vector<int>& nums, int target) {
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == target) return i;
        }
        return -1;
    }
};