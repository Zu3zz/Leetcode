"""
solution1 直接暴力

首先定义一个helper函数 用于判断当前数字是否符合ip地址的规则 即
1. 不能 为空
2. 首字母为0 但是字符串长度大于1 如 001
3. 数字大小大于255
上述三种情况 均不符合一个合法的ip地址

然后开始一个三重循环 对于i,j,k 分别代表IP地址字段第一 第二 第三个数
依次循环判断是否满足ip地址的规则，如果满足就append到res数组中
"""
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        n = len(s)
        res = []
        def helper(tmp):
            if not tmp or (tmp[0] == "0" and len(tmp) >1) or int(tmp) > 255:
                return False
            return True
        for i in range(3):
            for j in range(i+1, i+4):
                for k in range(j+1, j+4):
                    if i < n and j < n and k < n:
                        tmp1 = s[:i+1]
                        tmp2 = s[i+1:j+1]
                        tmp3 = s[j+1:k+1]
                        tmp4 = s[k+1:]
                        
                        if all(map(helper, [tmp1, tmp2, tmp3, tmp4])):
                            res.append(tmp1 +"."+tmp2+"."+tmp3+"."+tmp4)
        return res