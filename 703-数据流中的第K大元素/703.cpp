class KthLargest {
// 本题有两种做法
// 1. 使用普通的数组，每一次存储新来的数据流中的值 做一次排序
// 假设数据流中有k个元素 那么时间复杂度为K(个数)*nlogn(排序时间复杂度)
// 2. 使用优先队列的数据结构 并且按照小根堆来做 即按照树的形式来存储k个数据
// 其中最小值始终在最上面 当来了一个新的数据时 判断 如果比最小值还小 那么直接扔掉不看
// 如果大于最小值 那么就把当前的最小值扔掉 新的元素存进优先队列中 优先队列自己内部重新排列一次
// 依旧假设有k个元素 那么时间复杂度可以从K*1 到K*logn(优先队列的自我内部重排)
// 可以发现 明显优于第一种算法
// leetcode 的通过时间为36ms 最快的solution思路相同 做了一些优化 可以达到24ms	
public:
    KthLargest(int k, vector<int> nums) {
        size = k;
        for(int i=0;i<nums.size();i++){
            heap.push(nums[i]);
            if(heap.size()>k){
                heap.pop();
            }
        }
    }
    
    int add(int val) {
        heap.push(val);
        if(heap.size()>size){
            heap.pop();
        }
        return heap.top();
    }
private:
    priority_queue<int,vector<int>,greater<int>> heap;
    int size;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */