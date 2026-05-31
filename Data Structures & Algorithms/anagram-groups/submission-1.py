class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        list_hashmap = {}
        for i in range(0, len(strs)):
            alphabetCount = [0] * 26
            letterCount = 0
            while (letterCount < len(strs[i])):
                alphabetCount[ord(strs[i][letterCount]) - ord('a')] += 1
                letterCount+=1
                #we now have the alphabet key for this particular string
                #hash it to right spot
            if tuple(alphabetCount) in list_hashmap:
                list_hashmap[tuple(alphabetCount)].append(strs[i])
            else :
                list_hashmap[tuple(alphabetCount)] = [strs[i]]
        #we have a hashmap with all anagrams grouped by their alphabetCount
        return list(list_hashmap.values())

