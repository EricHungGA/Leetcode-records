class Solution:
    def isPalindrome(self, s: str) -> bool:
        #first convert all letters to lowercase and remove alphanumeric
        s = s.lower()

        #two pointers going from left and right side of the string to meet in middle
        r = 0
        l = len(s) - 1

        while r < l:
            if s[r].isalnum() == False or s[r] == ' ':
                r += 1
                continue
            if s[l].isalnum() == False or s[l] == ' ':
                l -= 1
                continue
            if s[r] == s[l]:
                r += 1
                l -= 1
                continue
            else:
                return False

        return True
