"""
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
"""


class Solution:
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        lst = []

        def generate(str, left, right):
            if left < right:
                return
            if left == 0 and right == 0:
                lst.append(str)
                return
            if left > 0:
                generate(str + ")", left - 1, right)
            if right > 0:
                generate(str + "(", left, right - 1)

        generate('', n, n)
        return lst
