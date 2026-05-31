class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        hashSet = {}
        for letter in s:
            if letter in hashSet:
                hashSet[letter] += 1
            else:
                hashSet[letter] = 1
        for letter in t:
            if letter in hashSet:
                if hashSet[letter] > 0:
                    hashSet[letter] -= 1
                else:
                    return False
            else:
                return False
        result = 0
        for letter in hashSet:
            result += hashSet[letter]
        if result == 0:
            return True
        else:
            return False