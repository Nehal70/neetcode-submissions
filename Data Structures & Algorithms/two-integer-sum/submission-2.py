class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashSet = {}
        for i in range(len(nums)):
            num = nums[i]
            if num in hashSet:
                return [hashSet[num], i]
            hashSet[target - num] = i
        return False