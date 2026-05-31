class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        #max frequency can be the length of the actual array
        resultList = [[] for i in range(len(nums) + 1)]
        hashList = {}
        for num in nums:
            if num in hashList:
                hashList[num] += 1
            else:
                hashList[num] = 1
        #Now, hashList contains key of each unique number and corresponding value being its frequency

        #populate resultList
        for key, value in hashList.items():
            resultList[value].append(key)     

        result = []
        #parse through resultList
        for i in range(len(resultList) - 1, -1, -1):
            if resultList[i]:
                for num in resultList[i]:
                    result.append(num)
                    if len(result) == k:
                        return result