class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        i = 0
        while ( i < len(nums)):
            item = nums[i]
            temp_target = target - item 
            if temp_target in hashmap :
                return [hashmap[temp_target], i]
            hashmap[item] = i
            i += 1
        
            
            