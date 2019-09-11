"""
这里我们使用回溯法
backtrace函数接受三个参数
1. i当前指针的位置
2. tmp代表当前已经添加的所有字符串
3. flag代表当前已经确定了多少ip地址

在backtrace的过程中 主要判断当前字符串即ip地址的大小 根据大小进行判断怎么添加

但是很神奇 回溯居然比暴力要慢。。 也不知道怎么搞得
"""

class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        n = len(s)
        res = []
        def backtrace(i, tmp, flag):
            if flag == 0 and i == n:
                res.append(tmp[:-1])
                return
            if flag < 0:
                return
            for j in range(i, i+3):
                if j < n:
                    if i == j and s[j] == "0":
                        backtrace(j+1, tmp+s[j]+".", flag-1)
                        break
                    if 0 < int(s[i:j+1]) <= 255:
                        backtrace(j+1, tmp+s[i:j+1]+".", flag-1)
        
        backtrace(0,"",4)
        return res