"""
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.


Example:

Input: "cbbd"

Output: "bb"
"""


class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s:
            return ""
        len_s = len(s)
        if len_s == 0:
            return s
        start, end = 0, 1
        i = 0
        while i < len_s:
            if (end - start) >= ((len_s - i) * 2 - 1):
                break
            left, right = i, i + 1
            while right < len_s and s[right - 1] == s[right]:
                right += 1
            i = right
            while left - 1 >= 0 and right < len_s and s[left - 1] == s[right]:
                left -= 1
                right += 1
            if right - left > end - start:
                start = left
                end = right
        return s[start:end]
