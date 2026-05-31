class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        #make a hashmap
        hashmap = {chr(ord('a') + i): 0 for i in range(26)}
        #loop through strings
        sCount = 0
        tCount = 0
        while (sCount < len(s)):
            item = s[sCount]
            hashmap[item] += 1
            sCount += 1
        while (tCount < len(t)):
            item = t[tCount]
            hashmap[item] -= 1
            tCount += 1
        for i in range (ord('a'), ord('z')):
            if hashmap[chr(i)] == 0:
                continue
            else:
                return False
        return True



