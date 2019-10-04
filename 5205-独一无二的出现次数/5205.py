"""
执行用时 :32 ms, 在所有 Python3 提交中击败了100.00%的用户
内存消耗 :13.9 MB, 在所有 Python3 提交中击败了100.00%的用户
"""
class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        a = collections.Counter(arr)
        b = set()
        for k,v in a.items():
            b.add(v)
        return len(b) == len(a)