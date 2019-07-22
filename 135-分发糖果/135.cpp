class Solution {
  /*
  使用一个数组 做两次循环
  第一次循环从左往右
  只要右边一个孩子比左边一个孩子分数高 那么就让右边孩子的糖果数量比左边多一个 否则就只有1个糖果
  一遍循环过后 走右边往左的循环 逻辑与上述相同 即 只要左边的孩子分数比他右手边的孩子高 那么左边孩子的糖果数比右边多一个 否则只有一个
  同时在过程中进行判断 两次循环对应位置上的糖果数量的最大值
  e.g.
  input: [1,2,87,87,87,2,1]
  first cir: [1,2,3,1,1,1,1]
  second cir: [1,1,1,1,3,2,1]
  两次中的最大值则为[1,2,3,1,3,2,1] 加在一起为13 即为所求输出
  */
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> v(n,1);
        int res = 0;
        for(int i = 1;i<n;++i){
            if(ratings[i] > ratings[i-1])
                v[i] = v[i-1] + 1;
        }
        for(int i = n-2;i>=0;i--){
            if(ratings[i] > ratings[i+1]){
                v[i] = max(v[i], v[i+1] + 1);   
            }
        }
        return accumulate(v.begin(), v.end(), 0);
    }
};