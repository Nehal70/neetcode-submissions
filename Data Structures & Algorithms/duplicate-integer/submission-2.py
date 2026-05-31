class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        i = 0
        hashmap = {}
        while (i < len(nums)):
            item = nums[i]
            if item in hashmap :
                return True
            else :
                hashmap[item] = True
            i += 1
        return False