static const auto io_sync_off=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();
class Solution {
public:
	// 利用位运算 消去二进制的最后一位1 复杂度为有n个1 那就是n*O(1)
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n!=0){
        	// 位运算 将最后一位1消去
            n = n &(n-1);
            count++;
        }
        return count;
    }
};