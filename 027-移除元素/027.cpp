class Solution {
	/*
	此solution共花费4ms的执行时间
	可以直接使用c++的迭代器实现 依次查询
	如果查询到与val值相同的 直接erase掉 由于nums长度会改变 所以erase之后迭代器不发生变化
	只有不相同时 迭代器才会自+1;
	直接返回数组长度即可
	*/
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator it = nums.begin();
        for(;it!=nums.end();){
            if(*it == val){
                it = nums.erase(it);
            }
            else{
                it++;
            }
        }
        return nums.size();
    }
};