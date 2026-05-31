class Solution:
    def trap(self, height: List[int]) -> int:
        
        left = 0
        right = len(height) - 1
        max_left = height[left]
        max_right = height[right]
        total_vol = 0

        while (left < right):
            if(max_right < max_left):
                right -= 1
                max_right = max(max_right, height[right])
                total_vol += max_right - height[right]
            else:
                left += 1
                max_left = max(max_left, height[left])
                total_vol += max_left - height[left]
        
        return total_vol



        