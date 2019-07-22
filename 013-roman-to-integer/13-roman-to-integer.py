"""
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
"""


class Solution:
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        roman = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}
        total = 0
        for index in range(len(s) - 1):
            type = 1 if roman[s[index]] >= roman[s[index + 1]] else -1
            total += type * roman[s[index]]
        return total + roman[s[len(s) - 1]]
