static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
    return nullptr;
}();  // untie in/out streams

class Solution {
public:
	/*
	本solution经过上面一段黑科技代码加持 可以从16ms提高到8ms
	共有4种做法 本做法是最简介的（个人感觉
	1.暴力 O(n^2) 2.map O(n) 3.排序 O(nlogn) 4.divide & conquer O(n)-O(nlogn)不等
	使用map存储所有数字出现的频率
	使用一个map的迭代器遍历map 申明两个变量 max 和value 分别用来存储最大的频率(value)和其对应的数值(key)
	直接输出对应的key即可
	*/
    int majorityElement(vector<int>& nums) {
        map<int,int> map1;
        for(int i = 0 ;i<nums.size();i++){
            map1[nums[i]]+=1;
        }
        int max = 0;
        int value = 0;
        map<int,int>::iterator it;//使用迭代器
        for(it = map1.begin();it!=map1.end();it++){
            if(it->second>=max){
                max = it->second;// 存储value
                value = it->first;// 存储key
            }
        }
        return value;
    }
};