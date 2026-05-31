class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        list1 = {}
        for i in range (len(nums)):
            if ((nums[i]) in list1):
                return True 
            list1[nums[i]] = 1
        return False

