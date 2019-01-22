class Solution {
public:
    // 本题的解法可以使用双向队列
    // 首先申明一个deque 用来存储每一次滑动的大小为k的窗口中最大值在所给的数组中的下标
    // 再最后从deque中拿到所有的最大值放入定义好的vector中返回
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> vec;
        int n = nums.size();
        if(k>n || n==0){
            return vec;
        }
        for(int i = 0;i<n;i++){
            if(!dq.empty()){
                if(i>=dq.front()+k){
                    dq.pop_front();
                }
                while(!dq.empty() && nums[i]>nums[dq.back()]){
                    dq.pop_back();
                }
            }
            dq.push_back(i);
            if(i+1>=k){
                vec.push_back(nums[dq.front()]);
            }
        }
        return vec;
    }
};