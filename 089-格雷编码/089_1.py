"""
非常tricky的solution
由于输出结果都是由十进制表示 所以直接使用位运算 保存十进制结果即可
首先由格雷码的属性来看 格雷码的个数都是2**n个
为了方便观看 我们下面用2进制表示所有数
n = 0;grey = [0]
n = 1;grey = [0,1]
n = 2;grey = [00,01,10,11]
n = 3;grey = [000,001,010,011,111,110,101,100]
可以观察发现 每次格雷码都是一个与之前数组的镜像
对n = 3 可以分成前后两部分 各为长度为4的数组arr1[000,001,010,011]与arr2[111,110,101,100]
可以看到 arr1 其实就是n=2时 所有格雷码前面+0 而arr2 则是对n=2的格雷码数组逆序遍历 前面均添加1
由此可以得到格雷码的生成公示 即下面代码表示
"""
class Solution:
    def grayCode(self, n: int) -> List[int]:
        res,k = [0],1
        if n == 0:
            return res
        for i in range(n):
            for j in range(len(res)-1,-1,-1):
                res.append(res[j] + k)
            k <<= 1
        return res