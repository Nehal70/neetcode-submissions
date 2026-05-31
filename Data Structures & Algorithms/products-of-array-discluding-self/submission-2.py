class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        leftProducts = [1] * len(nums)
        rightProducts = [1] * len(nums) 

        #calculating left products
        leftProducts[0] = 1
        product = nums[0]
        for i in range(1, len(nums)):
            leftProducts[i] = product
            product = product * nums[i]

        #calculate right products
        rightProducts[-1] = 1
        product = nums[-1]
        for i in range(len(nums) - 2, -1, -1):
            rightProducts[i] = product
            product = product * nums[i]
        
        #resultant array
        result = [1] * len(nums)
        for i in range(len(nums)):
            result[i] = leftProducts[i] * rightProducts[i]
        
        return result
