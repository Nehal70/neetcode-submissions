class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        leftProducts = [1] * len(nums)
        rightProducts = [1] * len(nums)

        for i in range (len(nums)):
            if i == 0:
                leftProducts[i] = 1
            else : 
                leftProducts[i] = leftProducts[i - 1] * nums[i - 1]
        
        for i in range (len(nums) - 1, -1, -1):
            if i == len(nums) - 1:
                rightProducts[i] = 1
            else : 
                rightProducts[i] = rightProducts[i + 1] * nums[i + 1]

        output = [1] * len(nums)
        for i in range (len(nums)):
            output[i] = leftProducts[i] * rightProducts[i]

        return output