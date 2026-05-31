class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagramSet = {}
        for word in strs:
            #create alphabet count for this word
            alphabetCount = [0] * 26
            for letter in word:
                alphabetCount[ord(letter)-ord('a')] += 1
            #check if alphabet count already exists
            if tuple(alphabetCount) in anagramSet:
                anagramSet[tuple(alphabetCount)].append(word)
            else:
                anagramSet[tuple(alphabetCount)] = [word]
        
        #print result
        result = []
        for key, value in anagramSet.items():
            result.append(value)
        #return result
        return result