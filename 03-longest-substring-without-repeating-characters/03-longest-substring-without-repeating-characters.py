"""
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

"""

class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        count,start,find = 0,0,[False for _ in range(256)]
        for i,v in enumerate(s):
            if not find[ord(v)]:
                find[ord(v)] = True
            else:
                while v != s[start]:
                    find[ord(s[start])] = False
                    start+=1
                start+=1
            count = max(count,i-start+1)
        return count