class Solution:
    def maxArea(self, heights: List[int]) -> int:
        left = 0
        right = len(heights) - 1
        max_vol = 0

        while (left < right):
            if (heights[left] <= heights[right]):
                if (heights[left] * (right - left) > max_vol):
                    max_vol = heights[left] * (right - left)
                left += 1
            else: 
                if (heights[right] * (right - left) > max_vol):
                    max_vol = heights[right] * (right - left)
                right -= 1
        
        return max_vol



               
