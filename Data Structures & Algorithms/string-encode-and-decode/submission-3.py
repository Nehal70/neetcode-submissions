class Solution:

    def encode(self, strs: List[str]) -> str:

        result = ""

        for word in strs:
            counter = 0
            result_word = ""
            for letter in word:
                result_word += letter
                counter += 1
            result_word = str(counter) + "#" + result_word
            result += result_word

        return result

    def decode(self, s: str) -> List[str]:
        result = []
        i = 0

        while i < len(s):
            j = i
            while s[j] != '#':
                j += 1

            length = int(s[i:j]) 
            i = j + 1  
            word = s[i:i+length]
            result.append(word)
            i += length 
            
        return result

            









