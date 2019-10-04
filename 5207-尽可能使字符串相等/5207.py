"""
执行用时 :100 ms, 在所有 Python3 提交中击败了66.42%的用户
内存消耗 :15.2 MB, 在所有 Python3 提交中击败了100.00%的用户
"""
class Solution:
    def equalSubstring(self, s: str, t: str, maxCost: int) -> int:
        n = len(s)
        a = []
        for i in range(n):
            a.append(abs(ord(s[i]) - ord(t[i])))
        l,r,cur,res = 0,-1,0,0
        while l < n:
            if cur <= maxCost:
                res = max(res, r-l+1)
            if cur <= maxCost and r+1 < n:
                r+=1
                cur += a[r]
            else:
                cur -= a[l]
                l+=1
        return res
        