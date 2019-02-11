// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
	/*
	执行时间0ms
	二分法 左边界为1 右边界为n
	为了避免移除 mid =l + (r-l) /2
	需要注意的是 本题true和false的定义是反的 需要仔细审题
	*/
public:
    int firstBadVersion(int n) {
        long l = 1;
        long r = n;
        while(l < r){
            auto mid = l + (r-l) /2;
            if(isBadVersion(mid)){
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
};