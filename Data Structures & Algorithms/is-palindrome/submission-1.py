class Solution:
    def isPalindrome(self, s: str) -> bool:
        
        s = s.lower().replace(" ", "")
        #left pointer
        i = 0
        #right pointer
        j = len(s) - 1

        while (i <= j):
            if (s[i].isalnum()):
                if (s[j].isalnum()):
                    if (s[i] == s[j]):
                        i += 1
                        j -= 1
                    else:
                        return False
                else : 
                    j -= 1
            else : 
                i += 1
        return True

        """
        i = 0
        j = len(s) - 1

        while(i <=  j):
            if (s[i].isalnum()):
                if(s[j].isalnum()):
                    if(s[j].lower() == s[i].lower()):
                        i += 1
                        j -= 1
                    else:
                        return False
                else:
                    j -= 1
            else: i += 1
        return True
        """



