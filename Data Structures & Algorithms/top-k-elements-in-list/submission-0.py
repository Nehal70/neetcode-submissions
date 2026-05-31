class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        #to store cout of each num
        counts = {}
        buckets = [[] for i in range(0, len(nums) + 1)]
        for number in nums:
            if number in counts:
                counts[number] += 1
            else :
                counts[number] = 1
        #should have a hashmap with each number's frequency
        for key, value in counts.items():
            buckets[value].append(key)
        
        i = len(buckets) - 1
        output = []
        while (i >= 0):
            for number in buckets[i]:
                output.append(number)
            if len(output) == k:
                return output
            i-=1;