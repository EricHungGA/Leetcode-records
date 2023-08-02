class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # return LENGTH of the non-repeat substring

        # edge case for len(s) being less than 2
        if len(s) < 2:
            return len(s)
        
        # initalize two pointers starting at same side
        l, r = 0, 0 
        # recording the unique letters in a hash
        hashmap = {}
        maxL = 0

        while r < len(s):
            # check if the letter was already recorded for this substring
            if s[r] in hashmap.keys():
                #record the length of the hash
                maxL = max(len(hashmap), maxL)
                hashmap = {}
                l += 1
                r = l
            # add the letters into my hash
            else:
                hashmap[s[r]] = 1
                r += 1
        maxL = max(len(hashmap), maxL)
        
        return maxL