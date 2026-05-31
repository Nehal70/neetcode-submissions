class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:

        numset = set(nums)
        longest = 0

        for num in numset:
            if num - 1 not in numset:
                length = 1
                current = num + 1

                while current in numset:
                    length += 1
                    current += 1

                longest = max(longest, length)

        return longest


        